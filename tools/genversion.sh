#!/bin/sh

# Get version from VERSION file
VERSION=$(cat VERSION 2>/dev/null || echo "unknown")

# Get short commit hash
if git rev-parse --short HEAD >/dev/null 2>&1; then
    GIT_COMMIT=$(git rev-parse --short HEAD)
else
    GIT_COMMIT="nogit"
fi

# Detect uncommitted changes (dirty)
GIT_DIRTY=""
git diff --quiet 2>/dev/null || GIT_DIRTY="-dirty"
git diff --cached --quiet 2>/dev/null || GIT_DIRTY="${GIT_DIRTY}-staged"

# Get build timestamp
BUILD_DATE=$(date +"%Y-%m-%d %H:%M:%S")

# Generate the header
cat > kernel/version.h <<EOF
#ifndef _VERSION_H_
#define _VERSION_H_

#define OS_VERSION "${VERSION}"
#define GIT_COMMIT "${GIT_COMMIT}${GIT_DIRTY}"
#define BUILD_DATE "${BUILD_DATE}"

#endif
EOF
