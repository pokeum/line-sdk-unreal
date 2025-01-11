#!/bin/zsh

# Validating variables
isValid=1
list=(
  "doxygenGenerator_DOXYGEN_PATH" 
  "doxygenGenerator_INPUT_DIRECTORY" 
  "doxygenGenerator_OUTPUT_DIRECTORY" 
  "doxygenGenerator_PROJECT"
  "doxygenGenerator_SYNOPSIS"
  "doxygenGenerator_VERSION"
)
for item in "${list[@]}"; do
  if [ -v $item ]; then
    echo "The environment variable \"$item\" is set."
  else
    echo "The environment variable \"$item\" is not set."
    isValid=0
  fi
done
if [ "$isValid" -eq 0 ]; then
  exit 1
fi


SCRIPT_DIR=$(dirname "$(realpath "$0")")
CALL_DIR=$(pwd)

FILES_PATH="$SCRIPT_DIR/Files"


# Reset
rm -rf "$doxygenGenerator_OUTPUT_DIRECTORY/Doxyfile"
rm -rf "$doxygenGenerator_OUTPUT_DIRECTORY/html"


# Add the Doxyfile
DOXY_FILE_SOURCE="$FILES_PATH/Doxyfile"
DOXY_FILE_DESTINATION="$doxygenGenerator_OUTPUT_DIRECTORY/Doxyfile"
cp $DOXY_FILE_SOURCE $DOXY_FILE_DESTINATION

# Add doxygen-awesome
mkdir -p "$doxygenGenerator_OUTPUT_DIRECTORY/html"

DOXYGEN_AWESOME_SOURCE="$FILES_PATH/doxygen-awesome"
DOXYGEN_AWESOME_DESTINATION="$doxygenGenerator_OUTPUT_DIRECTORY/html/doxygen-awesome"

cp -r $DOXYGEN_AWESOME_SOURCE $DOXYGEN_AWESOME_DESTINATION

# Add doxygen-custom
DOXYGEN_CUSTOM_SOURCE="$FILES_PATH/doxygen-custom"
DOXYGEN_CUSTOM_DESTINATION="$doxygenGenerator_OUTPUT_DIRECTORY/html/doxygen-custom"

cp -r $DOXYGEN_CUSTOM_SOURCE $DOXYGEN_CUSTOM_DESTINATION

# Add logo
LOGO_SOURCE="$FILES_PATH/logo.drawio.svg"
LOGO_DESTINATION="$doxygenGenerator_OUTPUT_DIRECTORY/html/logo.drawio.svg"

cp -r $LOGO_SOURCE $LOGO_DESTINATION

# Update Doxyfile parameters
declare -A map=(
  ["PROJECT_NAME[[:space:]]*="]="PROJECT_NAME           = \"$doxygenGenerator_PROJECT\""
  ["PROJECT_BRIEF[[:space:]]*="]="PROJECT_BRIEF          = \"$doxygenGenerator_SYNOPSIS\""
  ["PROJECT_NUMBER[[:space:]]*="]="PROJECT_NUMBER         = \"$doxygenGenerator_VERSION\""
  ["INPUT[[:space:]]*="]="INPUT                  = \"$doxygenGenerator_INPUT_DIRECTORY\""
  ["OUTPUT_DIRECTORY[[:space:]]*="]="OUTPUT_DIRECTORY       = \"$doxygenGenerator_OUTPUT_DIRECTORY\""
  ["{{DOXYGEN_AWESOME_PATH}}"]="$DOXYGEN_AWESOME_DESTINATION"
  ["{{DOXYGEN_CUSTOM_PATH}}"]="$DOXYGEN_CUSTOM_DESTINATION"
)
for key value in "${(@kv)map}"; do
    gsed -i "s#$key#$value#g" "$DOXY_FILE_DESTINATION"
done

# Run doxygen
$doxygenGenerator_DOXYGEN_PATH $DOXY_FILE_DESTINATION