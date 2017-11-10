/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2017 Treasure Data Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_OUT_KAFKA_CONFIG_H
#define FLB_OUT_KAFKA_CONFIG_H

#include "rdkafka.h"

#define FLB_KAFKA_BROKERS   "127.0.0.1"
#define FLB_KAFKA_TOPIC     "fluent-bit"
#define FLB_KAFKA_TS_KEY    "@timestamp"

struct flb_kafka {
    /* Config Parameters */
    char *brokers;

    int timestamp_key_len;
    char *timestamp_key;

    int message_key_len;
    char *message_key;

    /* Internal */
    rd_kafka_t *producer;
    rd_kafka_conf_t *conf;
    rd_kafka_topic_t *topic;
};

struct flb_kafka *flb_kafka_conf_create(struct flb_output_instance *ins,
                                        struct flb_config *config);
int flb_kafka_conf_destroy(struct flb_kafka *ctx);

#endif