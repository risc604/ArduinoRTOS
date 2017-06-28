#pragma once

#include "boost/preprocessor.hpp"




// -----------------------------------------------------------------------------
// ------------------------- Static Queue --------------------------------------
// -----------------------------------------------------------------------------
#define aDefineStaticQueue(qName , elSize , elCount) \
static uint8_t BOOST_PP_CAT(qName, _StaticBuffer)[elSize * elCount]; \
static StaticQueue_t BOOST_PP_CAT(qName, _StaticQueue); \
QueueHandle_t BOOST_PP_CAT(qName, _QueueHandle);

#define aImportStaticQueue(qName) \
extern QueueHandle_t BOOST_PP_CAT(qName, _QueueHandle);

#define aGetStaticQueueName(qName) BOOST_PP_CAT(qName, _QueueHandle)

#define aInitStaticQueue(qName, elSize, elCount) \
BOOST_PP_CAT(qName, _QueueHandle) = xQueueCreateStatic(elCount, elSize, BOOST_PP_CAT(qName, _StaticBuffer), & BOOST_PP_CAT(qName, _StaticQueue));



// -----------------------------------------------------------------------------
// -------------------------- Static Task --------------------------------------
// -----------------------------------------------------------------------------
#define aDefineStaticTask(tName, tStackSize) \
static StaticTask_t BOOST_PP_CAT(tName, _StaticTask); \
static TaskHandle_t BOOST_PP_CAT(tName, _TaskHandle); \
static StackType_t BOOST_PP_CAT(tName, _StackSpace)[tStackSize]; \

#define aGetStaticTaskName(tName) BOOST_PP_CAT(tName, _TaskHandle);

#define aCreateTask(tName, tFunction, tParams, tPriority) \
BOOST_PP_CAT(tName, _TaskHandle) = xTaskCreateStatic(tFunction, (const char *) #tName, sizeof(BOOST_PP_CAT(tName, _StackSpace)) / sizeof(StackType_t), (void*)tParams, tPriority, BOOST_PP_CAT(tName, _StackSpace), &BOOST_PP_CAT(tName, _StaticTask));
