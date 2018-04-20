#!/bin/tcsh
############################
#
# run_plotResiVsLayer.sh
# 
# This is a shell script which will 
# run the executable, plotResiVsLayer,
# and put the .eps files and .root files
# in the appropriate places.
#
# Matt Bellis
# 12/15/05
#
############################

#
# Test to see if some environment variables
# are set
#
set test = `printenv | grep DCALIGN`
if( $test == "" ) then 
    echo
    echo Environment variable DCALIGN is not defined
    echo
    exit(-1)
endif

#
# Write out the usage
#
if($# < 1) then
  echo
	echo "Wrong number of arguments"
  echo
  echo "Usage: run_plotResiVsLayer.sh <pass number>"
  echo
endif

#
# Make whatever directories are needed
#
if(! -e ./rootFiles)then
  echo
  echo "Making directory ./rootFiles" 
  echo
  mkdir ./rootFiles
endif

if(! -e ./Plots)then
  echo
  echo "Making directory ./Plots" 
  echo
  mkdir ./Plots
endif


#
# Run everything
#
set pass = pass$1
echo Looking in $DCALIGN/$pass
plotResiVsLayer -p $pass $DCALIGN/$pass/*.root

mv canvas[012].$pass.ResiVsLayer.eps Plots/.
mv $pass.ResiVsLayer.root rootFiles/.
