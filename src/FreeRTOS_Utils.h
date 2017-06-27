#pragma once

#include "boost/preprocessor.hpp"
#include "boost/preprocessor/cat.hpp"

#define aDefineStaticQueue(qName , elSize , elCount) \
static uint8_t BOOST_PP_CAT(qName, _StaticBuffer)[elSize * elCount]; \
static StaticQueue_t BOOST_PP_CAT(qName, _StaticQueue); \
QueueHandle_t BOOST_PP_CAT(qName, _QueueHandle);

#define aImportStaticQueue(qName) \
extern QueueHandle_t BOOST_PP_CAT(qName, _QueueHandle);

#define aGetStaticQueueName(qName) \
BOOST_PP_CAT(qName, _QueueHandle)

#define aInitStaticQueue(qName, elSize, elCount) \
aGetQueueName(qName) = xQueueCreateStatic(elCount, elSize, BOOST_PP_CAT(qName, _StaticBuffer) ,&(BOOST_PP_CAT(qName, _StaticQueue));
