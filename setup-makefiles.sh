#!/bin/sh

set -e

export DEVICE=surnia
export VENDOR=motorola
./../../$VENDOR/msm8916-common/setup-makefiles.sh $@
