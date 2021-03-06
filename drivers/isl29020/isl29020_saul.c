/*
 * Copyright (C) 2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     driver_isl29020
 * @{
 *
 * @file
 * @brief       ISL29020 adaption to the RIOT actuator/sensor interface
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include <string.h>

#include "saul.h"
#include "isl29020.h"

static int read(const void *dev, phydat_t *res)
{
    res->val[0] = (int16_t)isl29020_read((const isl29020_t *)dev);
    memset(&(res->val[1]), 0, 2 * sizeof(int16_t));
    res->unit = UNIT_CD;
    res->scale = 0;
    return 1;
}

const saul_driver_t isl29020_saul_driver = {
    .read = read,
    .write = saul_notsup,
    .type = SAUL_SENSE_LIGHT,
};
