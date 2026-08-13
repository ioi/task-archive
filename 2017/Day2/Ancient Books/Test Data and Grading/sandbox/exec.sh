#!/bin/bash

problem_name=books
sandbox=$(dirname "$0")

"${sandbox}/${problem_name}.exe" "$@"
