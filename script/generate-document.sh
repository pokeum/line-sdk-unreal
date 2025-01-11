#!/bin/zsh

SCRIPT_DIR=$(dirname "$(realpath "$0")")
CALL_DIR=$(pwd)

LINE_SDK_PATH="$SCRIPT_DIR/../Line_SDK_Unreal/Plugins/LineSDK"

export doxygenGenerator_DOXYGEN_PATH=$(which doxygen)
export doxygenGenerator_INPUT_DIRECTORY=$LINE_SDK_PATH/Source/LineSDK/Public
export doxygenGenerator_OUTPUT_DIRECTORY=$SCRIPT_DIR/../docs
export doxygenGenerator_PROJECT="UNOFFICIAL LINE SDK for Unreal"
export doxygenGenerator_SYNOPSIS="The UNOFFICIAL LINE SDK for Unreal helps you develop a Unreal Engine game with engaging and personalized user experience."
export doxygenGenerator_VERSION=$(grep 'VersionName' "$LINE_SDK_PATH/LineSDK.uplugin" | sed 's/[^[:digit:].]//g')

mkdir -p $doxygenGenerator_OUTPUT_DIRECTORY

"$SCRIPT_DIR/../DoxygenGenerator/Generator.sh"