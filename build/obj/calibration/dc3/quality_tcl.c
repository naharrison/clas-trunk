

char quality_tcl_proc[]=
"#!/usr/bin/wish -f\n"
"\n"
"set smallfont  \"-*-helvetica-medium-o-*-*-9-*-*-*-*-*-*-*\"\n"
"set normalfont  \"-*-times-medium-r-*-*-14-*-*-*-*-*-*-*\"\n"
"set boldfont    \"-*-times-bold-o-*-*-10-*-*-*-*-*-*-*\"\n"
"set bigfont     \"-*-helvetica-medium-o-*-*-14-*-*-*-*-*-*-*\"\n"
"set bigboldfont \"-*-times-bold-r-*-*-14-*-*-*-*-*-*-*\"\n"
"set hugefont     \"-*-helvetica-medium-o-*-*-20-*-*-*-*-*-*-*\"\n"
"set hugeboldfont \"-*-times-bold-r-*-*-20-*-*-*-*-*-*-*\"\n"
"set fixedfont    \"-*-fixed-bold-*-*-*-12-*-*-*-*-*-*-*\"\n"
"\n"
"# spacing dimensions for tables in inches\n"
"set table_xspace 0.8\n"
"set table_yspace 0.16\n"
"\n"
"# flag for summary window existing\n"
"set summary_win_exists 0\n"
"\n"
"global quality_path\n"
"\n"
"\n"
"# This is run at program start time and creates widgets in\n"
"# the notebook page\n"
"proc calibration_quality {path} {\n"
"\n"
"   global quality_path\n"
"   global fixedfont\n"
"\n"
"   set quality_path $path\n"
"   \n"
"   set w $path.left\n"
"   frame $w -borderwidth 3 -relief groove\n"
"   label $w.lab -text \"Quality Test\"\n"
"   button $w.test -text \"Summary\" -command {QualityCheck}\n"
"   pack $w.lab $w.test -side top\n"
"   pack $w -side left -fill both\n"
"   \n"
"   set w $path.right\n"
"   frame $w\n"
"   pack $w -side right -fill both\n"
"   \n"
"   # stats\n"
"   set w $path.right.stats\n"
"   frame $w\n"
"   pack $w -side left -fill both\n"
"   label $w.tw -text \"Total Width    :    microns\" -anchor w -font $fixedfont\n"
"   label $w.ns -text \"Narrow sigma   :    microns\" -anchor w -font $fixedfont\n"
"   label $w.ws -text \"Wide sigma     :    microns\" -anchor w -font $fixedfont\n"
"   label $w.mn -text \"Mean           :    microns\" -anchor w -font $fixedfont\n"
"   label $w.ar -text \"Amplitude Ratio:           \" -anchor w -font $fixedfont\n"
"   pack $w.tw $w.ns $w.ws $w.mn $w.ar -side top -fill x\n"
"	\n"
"}\n"
"\n"
"# This is called from the Tcl-callable C routine QualityCheck.\n"
"# It creates the summary window (if it doesn't already exist)\n"
"# and draws the header and empty tables.\n"
"#\n"
"proc QualitySummary {} {\n"
"\n"
"   global normalfont boldfont bigboldfont bigfont smallfont hugeboldfont hugefont\n"
"   global filename\n"
"   global summary_win_exists\n"
"\n"
"   set w .qualsum\n"
"   if {[expr $summary_win_exists==0]} {\n"
"      toplevel $w\n"
"      frame $w.b\n"
"      pack $w.b -side bottom -fill x\n"
"   \n"
"      ################# Buttons ################\n"
"      button $w.b.dismiss -text \"Dismiss\" \\n"
"         -command {set summary_win_exists 0 ; destroy .qualsum}\n"
"      button $w.b.print -text \"Print...\" -command {PrintCanvasPS .qualsum.c.c}\n"
"      button $w.b.save -text \"Save as postscipt...\" -command {SaveCanvasPS .qualsum.c.c}\n"
"      pack $w.b.print $w.b.save -side left\n"
"      pack $w.b.dismiss -side right\n"
"   \n"
"      ################ Canvas ###############\n"
"      frame $w.c -borderwidth 3 -relief sunken\n"
"      pack $w.c -side top -fill both\n"
"      canvas $w.c.c -width 8.0i -height 10.0i -background \"#FFFFFF\"\n"
"      pack $w.c.c\n"
"      \n"
"      set summary_win_exists 1\n"
"   }\n"
"   \n"
"   set can $w.c.c\n"
"   $can delete ELEMENTS TABLES\n"
"   \n"
"   #----------- Header info ------------#\n"
"   set title [format \"Summary for %s\" $filename]\n"
"   $can create text 4.0i 0.5i -text $title -font $hugeboldfont -tags TABLES\n"
"\n"
"   set time [exec \"date\"]\n"
"   $can create text 0.2i 0.2i -text $time -font $smallfont -anchor w -tags TABLES\n"
"\n"
"   set user [exec \"whoami\"]\n"
"   $can create text 7.8i 0.2i -text $user -font $smallfont -anchor e -tags TABLES\n"
"   \n"
"   #---------- Table borders and labels --------#\n"
"   DrawTableTop  $can 1.0 1.2 \"Time residual sigmas,narrow (microns)\" \"SL\" \"avg.\"\n"
"   DrawTableSide $can 1.0 1.2 \"Sec\" \"avg.\"\n"
"   DrawTableTop  $can 1.0 3.0 \"Time residual sigmas,wide (microns)\" \"SL\" \"avg.\"\n"
"   DrawTableSide $can 1.0 3.0 \"Sec\" \"avg.\"\n"
"   DrawTableTop  $can 1.0 4.8 \"Time residual means (microns)\" \"SL\" \"avg.\"\n"
"   DrawTableSide $can 1.0 4.8 \"Sec\" \"avg.\"\n"
"   DrawTableTop  $can 1.0 6.6 \"Total width (microns)\" \"SL\" \"*avg.\"\n"
"   DrawTableSide $can 1.0 6.6 \"Sec\" \"*avg.\"\n"
"   DrawTableTop  $can 1.0 8.3 \"Hits per TBT\" \"sec\" \"total\"\n"
"   DrawTableTop  $can 1.0 9.0 \"Avg. Chisq. per DOF\" \"sec\" \"avg.\"\n"
"\n"
"}\n"
"\n"
"proc DrawTableTop {can xbase ybase title pre last} {\n"
"   \n"
"   global normalfont boldfont bigboldfont bigfont smallfont hugeboldfont hugefont\n"
"   global table_xspace table_yspace\n"
"   \n"
"   set y [format \"%fi\" [expr $ybase-0.25]]\n"
"   set x [format \"%fi\" [expr $xbase]]\n"
"   $can create text $x $y -text $title -font $bigboldfont -anchor w -tags TABLES\n"
"   set y [format \"%fi\" $ybase]\n"
"   for {set sl 1} {[expr $sl<=6]} {incr sl} {\n"
"      set x [format \"%fi\" [expr $xbase+($sl*$table_xspace)]]\n"
"      set lab [format \"%s%d\" $pre $sl]\n"
"      $can create text $x $y -text $lab -font $boldfont -anchor w -tags TABLES\n"
"   }\n"
"   set x [format \"%fi\" [expr $xbase+($sl*$table_xspace)]]\n"
"   $can create text $x $y -text $last -font $boldfont -anchor w -tags TABLES\n"
"\n"
"}\n"
"\n"
"proc DrawTableSide {can xbase ybase pre last} {\n"
"   \n"
"   global normalfont boldfont bigboldfont bigfont smallfont hugeboldfont hugefont\n"
"   global table_xspace table_yspace\n"
"   \n"
"   set x [format \"%fi\" $xbase]\n"
"   for {set sl 1} {[expr $sl<=6]} {incr sl} {\n"
"      set y [format \"%fi\" [expr $ybase+($sl*$table_yspace)]]\n"
"      set lab [format \"%s%d\" $pre $sl]\n"
"      $can create text $x $y -text $lab -font $boldfont -anchor w -tags TABLES\n"
"   }\n"
"   set y [format \"%fi\" [expr $ybase+($sl*$table_yspace)]]\n"
"   $can create text $x $y -text $last -font $boldfont -anchor w -tags TABLES\n"
"   \n"
"   # horizontal line\n"
"   set y [format \"%fi\" [expr $ybase+(6.0*$table_yspace)+0.08]]\n"
"   set x2 [format \"%fi\" [expr $xbase+(7.5*$table_xspace)]]\n"
"   $can create line $x $y $x2 $y -tags TABLES\n"
"\n"
"   # vertical line\n"
"   set x [format \"%fi\" [expr $xbase+(6.7*$table_xspace)+0.08]]\n"
"   set y [format \"%fi\" [expr $ybase]]\n"
"   set y2 [format \"%fi\" [expr $ybase+(7.5*$table_yspace)]]\n"
"   $can create line $x $y $x $y2 -tags TABLES\n"
"\n"
"}\n"
"\n"
"proc DrawTableElement {can xbase ybase i j val color} {\n"
"\n"
"   global normalfont boldfont bigboldfont bigfont smallfont hugeboldfont hugefont\n"
"   global table_xspace table_yspace\n"
"\n"
"   set x [format \"%fi\" [expr $xbase+($i*$table_xspace)]]\n"
"   set y [format \"%fi\" [expr $ybase+($j*$table_yspace)]]\n"
"   $can create text $x $y -text $val -font $normalfont -anchor w \\n"
"      -fill $color -tags ELEMENTS\n"
"}\n"
"\n"
"proc SaveCanvasPS {path} {\n"
"   global filename\n"
"\n"
"   set fname [tk_getSaveFile -initialfile [format \"%s.eps\" $filename]]\n"
"   if {[expr [string length $fname]<1]} {return}\n"
"\n"
"   $path postscript -file $fname\n"
"   puts [format \"Wrote %s\" $fname]\n"
"}\n"
"\n"
"proc PrintCanvasPS {path} {\n"
"   global filename\n"
"\n"
"   set fname [format \"dc3summary.tmp.%s.eps\" $filename]\n"
"\n"
"   $path postscript -file $fname\n"
"   puts [format \"executing: lpr %s\" $fname]\n"
"   exec lpr $fname\n"
"   exec rm -f $fname\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"

;
