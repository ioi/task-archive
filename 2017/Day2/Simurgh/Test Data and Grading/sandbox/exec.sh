#!/bin/bash

problem_name=simurgh
sandbox=$(dirname "$0")

"${sandbox}/${problem_name}.exe" "$@"
