#!/usr/bin/env bash
SINCE="2023-01-12"
git log --pretty=format: --name-only  --diff-filter=A --since=$SINCE keyboards/ | grep -i readme.md | sort -u
git log --pretty=format: --name-only  --diff-filter=A --since=$SINCE docs/
