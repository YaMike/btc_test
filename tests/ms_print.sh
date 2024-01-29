#!/usr/bin/bash

latest_result=$(ls -1t massif*| head -1)
ms_print "$latest_result"
