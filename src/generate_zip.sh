#!/usr/bin/env bash

project_name='prog3_pc3_teo2_v2023_2'
source_code='
  investment_simulator.h
  count_empty_cells.h
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}