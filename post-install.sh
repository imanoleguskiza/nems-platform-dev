#!/usr/bin/env bash

# Remove nems related sources if any.
rm -rf lib/features/nems
rm -rf lib/themes/nems

# Create clean folders
mkdir lib/features/nems
mkdir lib/themes/nems

# Copy the sources in place.
cp -r vendor/ec-europa/nems-platform/modules/features/* lib/features/nems
cp -r vendor/ec-europa/nems-platform/themes/* lib/themes/nems

echo NEMS Sources copied, make sure that you update your site.make for libraries and contribs
