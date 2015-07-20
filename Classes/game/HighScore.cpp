/* 
 * File:   HighScore.cpp
 * Author: dragomir
 * 
 * Created on 20 July 2015, 13:38
 */

#include "HighScore.h"

char* arkanoid::HighScore::storagePath = "highscore.txt";

arkanoid::HighScore::HighScore() {
  this->score = 0;
  
  FILE* file = fopen(arkanoid::HighScore::storagePath, "r");
  
  if (file) {
    // Read the high score from the file
    fscanf(file, "%d", &this->score);
    fclose(file);
  }
  else {
    // No highscore has ever been saved, just create an empty file and dump a 0 in there
    file = fopen(arkanoid::HighScore::storagePath, "w");
    fprintf(file, "%d", this->score);
    fclose(file);
  }
}

void arkanoid::HighScore::saveHighScore(int score) {
  if (score > this->score) {
    this->score = score;

    FILE* file = fopen(arkanoid::HighScore::storagePath, "w");

    if (file) {
      fprintf(file, "%d", this->score);
      fclose(file);
    }
  }
}

int arkanoid::HighScore::getHighScore() {
  return this->score;
}

arkanoid::HighScore::~HighScore() {
}

