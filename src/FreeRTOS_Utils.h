#pragma once

#include "boost/preprocessor.hpp"
#include "boost/preprocessor/cat.hpp"

#define defineStaticQueue(qName,elSize,elCount) \
static uint8_t BOOST_PP_CAT(qName,_StaticBuffer) [elSize * elCount]; \
static StaticQueue_t BOOST_PP_CAT(qName,_StaticQueue); \
static QueueHandle_t BOOST_PP_CAT(qName,_QueueHandle);

#define initializeStaticQueue( qName, elSize, elCount ) \
BOOST_PP_CAT(qName,_QueueHandle) = xQueueCreateStatic( elCount, elSize , BOOST_PP_CAT(qName,_StaticBuffer) , & BOOST_PP_CAT(qName,_StaticQueue));
