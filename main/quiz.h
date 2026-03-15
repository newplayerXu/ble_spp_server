/*
 * SPDX-FileCopyrightText: 2026 Educational Quiz Module
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

#ifndef QUIZ_H
#define QUIZ_H

#include <stdint.h>

// Maximum lengths for quiz content
#define MAX_QUESTION_LEN 256
#define MAX_OPTION_LEN 128
#define MAX_OPTIONS 4

// Quiz question structure
typedef struct {
    char question[MAX_QUESTION_LEN];
    char options[MAX_OPTIONS][MAX_OPTION_LEN];
    uint8_t correct_answer;  // Index of correct answer (0-3 for A-D)
} quiz_question_t;

/**
 * Initialize the quiz module
 */
void quiz_init(void);

/**
 * Get a specific quiz question by index
 * @param index Question index
 * @return Pointer to quiz question, or NULL if invalid index
 */
const quiz_question_t* quiz_get_question(uint8_t index);

/**
 * Get the total number of quiz questions
 * @return Number of questions available
 */
uint8_t quiz_get_question_count(void);

/**
 * Print a quiz question to the console
 * @param index Question index
 */
void quiz_print_question(uint8_t index);

/**
 * Check if an answer is correct
 * @param index Question index
 * @param answer Answer option (0-3 for A-D)
 * @return 1 if correct, 0 if incorrect
 */
uint8_t quiz_check_answer(uint8_t index, uint8_t answer);

#endif // QUIZ_H
