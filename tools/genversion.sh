#!/bin/sh

VERSION=$(cat VERSION 2>/dev/null || echo "unknown")
GIT_COMMIT=$(git rev-parse --short HEAD 2>/dev/null || echo "nogit")
GIT_DIRTY=$(git diff --quiet || echo "-dirty")

cat > kernel/version.h <<EOF
#ifndef _VERSION_H_
#define _VERSION_H_

#define OS_VERSION "${VERSION}"
#define GIT_COMMIT "${GIT_COMMIT}${GIT_DIRTY}"

#endif
EOF
