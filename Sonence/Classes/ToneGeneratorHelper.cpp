//
//  ToneGeneratorHelper.cpp
//  Sonence
//
//  Created by Benjamin Yu on 2012-10-14.
//
//

#include "ToneGeneratorHelper.h"
#import "ToneGenerator_objc.h"

namespace iOSBridge{
    
    ToneGeneratorHelper::ToneGeneratorHelper()
    {
        toneGenerator_objc = [[ToneGenerator_objc alloc] initWithBackground:@"OutThere_0.aiff"];
    }
    
    ToneGeneratorHelper::ToneGeneratorHelper(int numOfAsteroids)
    {
        toneGenerator_objc = [[ToneGenerator_objc alloc] init:numOfAsteroids];
    }
    
    ToneGeneratorHelper::~ToneGeneratorHelper(void)
    {
    }
        
    void ToneGeneratorHelper::playRandomTone()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)  Play];
    }
    
    void ToneGeneratorHelper::addTone(float frequency, double duration, int index)
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   AddTone: (int) floorf(frequency) timeConst:(double) duration toneNum:index];
    }

    void ToneGeneratorHelper::playConstantTone(float frequency, double duration, int index)
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   playConstantTone: (int) floorf(frequency) volume:(double) duration toneNum:index];
    }
    
    void ToneGeneratorHelper::playOscillatingTone(float frequency, double duration, int index)
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   playOscillatingTone:(int) floorf(frequency) timeConst:(double) duration toneNum:index];
    }
    
    void ToneGeneratorHelper::playDecreasingTone(float frequency, double duration, int index)
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   playDecreasingTone:(int) floorf(frequency) timeConst:(double) duration toneNum:index];
    }
    
    float ToneGeneratorHelper::removeTone(int index)
    {
        return [[((ToneGenerator_objc *)toneGenerator_objc)   RemoveTone:index] floatValue];
    }
    
    void ToneGeneratorHelper::play()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   Play];
    }
    
    void ToneGeneratorHelper::playBackgroundMusic(std::string fileName)
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   playBackgroundMusic:[NSString stringWithUTF8String:fileName.c_str()]];
    }
    
    void ToneGeneratorHelper::enableBackground()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   enableBackground];
    }
    
    void ToneGeneratorHelper::disableBackground()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   disableBackground];
    }
    
    void ToneGeneratorHelper::enableTones()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   ResumeTone];
    }
    
    void ToneGeneratorHelper::disableTones()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   PauseTone];
    }
    
    void ToneGeneratorHelper::maxToneVolume()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   MaxTone];
    }
    
    void ToneGeneratorHelper::playExplosion()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   playExplosion];
    }
    
    float ToneGeneratorHelper::getAmplitude()
    {
        return [[((ToneGenerator_objc *)toneGenerator_objc)   getAmplitude] floatValue];
    }
    
    void ToneGeneratorHelper::stop()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   Stop];
    }
    
    void ToneGeneratorHelper::oscillateBackground()
    {
        [((ToneGenerator_objc *)toneGenerator_objc)   oscillateBackground];
    }
    
    bool ToneGeneratorHelper::getToneStatus()
    {
        return [((ToneGenerator_objc *)toneGenerator_objc) getToneStatus];
    }
    
    bool ToneGeneratorHelper::getBackgroundStatus()
    {
        return [((ToneGenerator_objc *)toneGenerator_objc) getBackgroundStatus];
    }
    
    float ToneGeneratorHelper::getVolume()
    {
        float tmp = [((ToneGenerator_objc *)toneGenerator_objc) getVolume];
        return tmp;
    }
    
    int ToneGeneratorHelper::getMicVolume()
    {
        int tmp = [((ToneGenerator_objc *)toneGenerator_objc) getMicVolume];
        return tmp;
    }
    
    void ToneGeneratorHelper::setVolume(float level)
    {
        [((ToneGenerator_objc *)toneGenerator_objc) setVolume: level];
    }
    
    
    
    void ToneGeneratorHelper::calibrate()
    {
        for (int i = 0; i < 10; i++) {
            this->playConstantTone(1.0, 1.0, 0);
        }
    }
    
}