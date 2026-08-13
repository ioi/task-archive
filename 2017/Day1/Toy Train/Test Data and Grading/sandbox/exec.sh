#!/bin/bash

problem_name=train
sandbox=$(dirname "$0")

"${sandbox}/${problem_name}.exe" "$@"
