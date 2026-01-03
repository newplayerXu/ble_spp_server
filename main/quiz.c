/*
 * SPDX-FileCopyrightText: 2026 Educational Quiz Module
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

#include "quiz.h"
#include "esp_log.h"
#include <string.h>

static const char *TAG = "QUIZ";

// Quiz questions database
static const quiz_question_t quiz_questions[] = {
    {
        .question = "解放思想、实事求是是（ ）",
        .options = {
            "A. 马克思主义精髓",
            "B. 毛泽东思想精髓",
            "C. 邓小平理论精髓",
            "D. 是党的工作作风"
        },
        .correct_answer = 1  // B is the correct answer (index 1)
    }
};

static const uint8_t question_count = sizeof(quiz_questions) / sizeof(quiz_question_t);

void quiz_init(void)
{
    ESP_LOGI(TAG, "Quiz module initialized with %d questions", question_count);
}

const quiz_question_t* quiz_get_question(uint8_t index)
{
    if (index >= question_count) {
        ESP_LOGW(TAG, "Invalid question index: %d", index);
        return NULL;
    }
    return &quiz_questions[index];
}

uint8_t quiz_get_question_count(void)
{
    return question_count;
}

void quiz_print_question(uint8_t index)
{
    const quiz_question_t *q = quiz_get_question(index);
    if (q == NULL) {
        return;
    }
    
    ESP_LOGI(TAG, "Question %d: %s", index + 1, q->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        if (strlen(q->options[i]) > 0) {
            ESP_LOGI(TAG, "  %s", q->options[i]);
        }
    }
}

uint8_t quiz_check_answer(uint8_t index, uint8_t answer)
{
    const quiz_question_t *q = quiz_get_question(index);
    if (q == NULL) {
        return 0;
    }
    
    if (answer >= MAX_OPTIONS) {
        ESP_LOGW(TAG, "Invalid answer index: %d", answer);
        return 0;
    }
    
    uint8_t is_correct = (answer == q->correct_answer);
    if (is_correct) {
        ESP_LOGI(TAG, "Correct! Answer %c is correct.", 'A' + answer);
    } else {
        ESP_LOGI(TAG, "Incorrect. The correct answer is %c.", 'A' + q->correct_answer);
    }
    
    return is_correct;
}
