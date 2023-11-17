#include "client.h"
#include <iostream>

Client::Client(IOutputCompiler *initOutputCompiler,
               IInputProcessor *initInputProcessor,
               IInitializeInfo *initInitializer, ISaveInfo *initSaveInterface,
               Iterator *initIterator, Statistics *initStatisticsService,
               Helper *initHelper) {
  outputComipler_ = initOutputCompiler;
  inputProcessor_ = initInputProcessor;
  initializer_ = initInitializer;
  saveInterface_ = initSaveInterface;
  fieldIterator_ = initIterator;
  statisticsService_ = initStatisticsService;
  helper_ = initHelper;
  currentCommand_ = {GameCommand::HELP_COMMAND, GameCommand::HELP_LIST, 0, ""};
}
// Create request for command and read response
void Client::request() {
  outputComipler_->printRequest();
  currentCommand_ = inputProcessor_->parseCommand();
}

// Execute function reference to servers functions. Server choose with
// GameCommand enum
void Client::execute() {
  // check commandType
  switch (currentCommand_.commandType) {
  case GameCommand::HELP_COMMAND: {
    try {
      helper_->getInfoAboutCommand(outputComipler_,
                                   currentCommand_.helpCommandArgument);
    } catch (GameLogicException &exception) {
      outputComipler_->printError(exception);
    }
    break;
  }
  case GameCommand::HELP_LIST: {
    try {
      helper_->getInfoAboutCommand(outputComipler_, HELP_LIST);
    } catch (GameLogicException &exception) {
      outputComipler_->printError(exception);
    }
    break;
  }
  case GameCommand::DUMP: {
    try {
      saveInterface_->saveStateAndRules(currentCommand_.filename,
                                        outputComipler_);
    } catch (GameLogicException &exception) {
      outputComipler_->printError(exception);
    }
    break;
  }
  case GameCommand::EXIT: {
    exit(0);
    break;
  }
  case GameCommand::INITIALIZE: {
    try {
      initializer_->initializeStateAndRules(currentCommand_.filename,
                                            outputComipler_);
      statisticsService_->putInfo(outputComipler_);
    } catch (GameLogicException &gameException) {
      outputComipler_->printError(gameException);
    }
    break;
  }
  case GameCommand::STATISTICS: {
    statisticsService_->putInfo(outputComipler_);
    break;
  }
  case GameCommand::TICK: {
    fieldIterator_->goOnNTicks(currentCommand_.ticks);
    statisticsService_->putInfo(outputComipler_);
  } break;
  }
}

// just a setter
void Client::setCommandState(parseAnswerStruct initCommandStruct) {
  currentCommand_ = initCommandStruct;
}