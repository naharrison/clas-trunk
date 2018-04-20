

char tzero_tcl_proc[]=
"#!/usr/bin/wish -f\n"
"\n"
"set tzero_method 1\n"
"set tzero_plot_min 1\n"
"set tzero_plot_max 500\n"
"set tzero_fit_min 10\n"
"set tzero_fit_max 30\n"
"\n"
"proc find_tzero {win} {\n"
"   global sec sup\n"
"   global tlimt tlim_low\n"
"   global cancel_op\n"
"   global tzero\n"
"   global find_tzero_win\n"
"   global normalfont boldfont bigboldfont bigfont smallfont hugeboldfont hugefont\n"
"   global tzero_method\n"
"	global tzero_plot_min tzero_plot_max\n"
"	global tzero_fit_min tzero_fit_max\n"
"   \n"
"   set find_tzero_win $win\n"
"\n"
"	### Tzero Method #############\n"
"	set w $win.method\n"
"	frame $w\n"
"	pack $w -side top -fill x\n"
"	label $w.lab -text \"Method:\"\n"
"	radiobutton $w.mac -text \"Mac\" -variable tzero_method -value 1\n"
"	radiobutton $w.dave -text \"Dave\" -variable tzero_method -value 2 -state disabled\n"
"	pack $w.lab $w.mac $w.dave -side left -fill both\n"
"\n"
"	set w $win.limits\n"
"	frame $w -borderwidth 2 -relief groove\n"
"	pack $w -side top -fill both\n"
"	label $w.unitslab -text \"(units are histogram bins 1 to 500)\"\n"
"	pack $w.unitslab -side top -fill x\n"
"	set w $win.limits.f\n"
"	frame $w\n"
"	pack $w -side bottom -fill both\n"
"\n"
"	## Plot limits ############\n"
"	set w2 $w.plotlimits\n"
"	frame $w2 -borderwidth 2 -relief groove\n"
"	pack $w2 -side left -fill both\n"
"	label $w2.lab -text \"Plot Limits\"\n"
"	pack $w2.lab -side top -fill x\n"
"	frame $w2.max -borderwidth 1 -relief groove\n"
"	button $w2.max.minusten -text \"-100\" -padx 0 -command {ShiftTzeroLimit plotlimits.max -100}\n"
"	button $w2.max.minus -text \"-10\" -width 4 -padx 0 -command {ShiftTzeroLimit plotlimits.max -10}\n"
"	entry $w2.max.en -width 4\n"
"	button $w2.max.plus -text \"+10\" -width 4 -padx 0  -command {ShiftTzeroLimit plotlimits.max +10}\n"
"	button $w2.max.plusten -text \"+100\" -padx 0  -command {ShiftTzeroLimit plotlimits.max +100}\n"
"	label $w2.max.lab -text \"max\"\n"
"	pack $w2.max.lab -side left\n"
"	pack $w2.max.plusten $w2.max.plus $w2.max.en $w2.max.minus $w2.max.minusten  -side right\n"
"	frame $w2.min -borderwidth 1 -relief groove\n"
"	button $w2.min.minusten -text \"-100\" -padx 0 -command {ShiftTzeroLimit plotlimits.min -100}\n"
"	button $w2.min.minus -text \"-10\" -width 4 -padx 0 -command {ShiftTzeroLimit plotlimits.min -10}\n"
"	entry $w2.min.en -width 4\n"
"	button $w2.min.plus -text \"+10\" -width 4 -padx 0 -command {ShiftTzeroLimit plotlimits.min +10}\n"
"	button $w2.min.plusten -text \"+100\" -padx 0  -command {ShiftTzeroLimit plotlimits.min +100}\n"
"	label $w2.min.lab -text \"min\"\n"
"	pack $w2.min.lab -side left\n"
"	pack $w2.min.plusten $w2.min.plus $w2.min.en $w2.min.minus $w2.min.minusten  -side right\n"
"	pack $w2.max $w2.min -side top -fill both\n"
"\n"
"	$w2.min.en insert 0 $tzero_plot_min\n"
"	bind $w2.max.en <Return> NewTzeroPlotLimits\n"
"	$w2.max.en insert 0 $tzero_plot_max\n"
"	bind $w2.min.en <Return> NewTzeroPlotLimits\n"
"\n"
"	## Fit limits ##############\n"
"	set w2 $w.fitlimits\n"
"	frame $w2 -borderwidth 2 -relief groove\n"
"	pack $w2 -side right -fill both\n"
"	label $w2.lab -text \"Fit Limits\"\n"
"	pack $w2.lab -side top -fill x\n"
"	frame $w2.max -borderwidth 1 -relief groove\n"
"	button $w2.max.minusten -text \"-10\" -padx 0 -command {ShiftTzeroLimit fitlimits.max -10}\n"
"	button $w2.max.minus -text \"-1\" -width 3 -padx 0 -command {ShiftTzeroLimit fitlimits.max -1}\n"
"	entry $w2.max.en -width 4\n"
"	button $w2.max.plus -text \"+1\" -width 3 -padx 0  -command {ShiftTzeroLimit fitlimits.max +1}\n"
"	button $w2.max.plusten -text \"+10\" -padx 0  -command {ShiftTzeroLimit fitlimits.max +10}\n"
"	label $w2.max.lab -text \"max\"\n"
"	pack $w2.max.lab -side left\n"
"	pack $w2.max.plusten $w2.max.plus $w2.max.en $w2.max.minus $w2.max.minusten  -side right\n"
"	frame $w2.min -borderwidth 1 -relief groove\n"
"	button $w2.min.minusten -text \"-10\" -padx 0 -command {ShiftTzeroLimit fitlimits.min -10}\n"
"	button $w2.min.minus -text \"-1\" -width 3 -padx 0 -command {ShiftTzeroLimit fitlimits.min -1}\n"
"	entry $w2.min.en -width 4\n"
"	button $w2.min.plus -text \"+1\" -width 3 -padx 0 -command {ShiftTzeroLimit fitlimits.min +1}\n"
"	button $w2.min.plusten -text \"+10\" -padx 0  -command {ShiftTzeroLimit fitlimits.min +10}\n"
"	label $w2.min.lab -text \"min\"\n"
"	pack $w2.min.lab -side left\n"
"	pack $w2.min.plusten $w2.min.plus $w2.min.en $w2.min.minus $w2.min.minusten  -side right\n"
"	pack $w2.max $w2.min -side top -fill both\n"
"\n"
"	$w2.min.en insert 0 $tzero_fit_min\n"
"	bind $w2.max.en <Return> NewTzeroFitLimits\n"
"	$w2.max.en insert 0 $tzero_fit_max\n"
"	bind $w2.min.en <Return> NewTzeroFitLimits\n"
"\n"
"   ################# Tzero  ####################\n"
"   set w $win.tzero\n"
"   frame $w -borderwidth 3 -relief groove\n"
"   pack $w -side top -fill x\n"
"\n"
"   frame $win.tzero.ctls\n"
"   frame $win.tzero.find\n"
"   frame $win.tzero.lab\n"
"   pack $win.tzero.ctls -side right -fill both\n"
"   pack $win.tzero.lab $win.tzero.find -side left\n"
"\n"
"	label $win.tzero.lab.lab -text \"Set Tzero:\"\n"
"	pack $win.tzero.lab.lab -side top -fill y\n"
"   \n"
"   set w $win.tzero.ctls.sbf\n"
"   frame $w\n"
"   scrollbar $w.sb -orient horizontal\\n"
"      -command {scrollvalue $tlim_low $tlimt($sup) $find_tzero_win.tzero.ctls.sbf}\n"
"   entry $w.en -width 10 -textvariable tzero\n"
"   scrollvalue $tlim_low $tlimt($sup) $find_tzero_win.tzero.ctls.sbf moveto 0\n"
"   bind $w.sb <ButtonRelease> {set sec $sec}\n"
"   bind $w.en <KeyPress-KP_Enter> \\n"
"      {entryvalue $tlim_low $tlimt($sup) $find_tzero_win.tzero.ctls.sbf}\n"
"   bind $w.en <Return> \\n"
"      {entryvalue $tlim_low $tlimt($sup) $find_tzero_win.tzero.ctls.sbf}\n"
"   pack $w.sb -side left -fill x -expand 1\n"
"   pack $w.en -side left\n"
"   pack $w -side top -fill both\n"
"\n"
"   set w $win.tzero.ctls.delta\n"
"   frame $w\n"
"   button $w.hunplus -text \"+100\" -font $smallfont -command {DeltaTime 100 $find_tzero_win.tzero.ctls.sbf}\n"
"   button $w.tenplus -text \"+10\" -font $smallfont -command {DeltaTime 10 $find_tzero_win.tzero.ctls.sbf}\n"
"   button $w.oneplus -text \"+1\" -font $smallfont -command {DeltaTime 1 $find_tzero_win.tzero.ctls.sbf}\n"
"   pack $w.hunplus $w.tenplus $w.oneplus -side right\n"
"   button $w.hunminus -text \"-100\" -font $smallfont -command {DeltaTime -100 $find_tzero_win.tzero.ctls.sbf}\n"
"   button $w.tenminus -text \"-10\" -font $smallfont -command {DeltaTime -10 $find_tzero_win.tzero.ctls.sbf}\n"
"   button $w.oneminus -text \"-1\" -font $smallfont -command {DeltaTime -1 $find_tzero_win.tzero.ctls.sbf}\n"
"   pack $w.hunminus $w.tenminus $w.oneminus -side left\n"
"   pack $w -side bottom -fill both\n"
"\n"
"	## Middle frame for fit buttons and Info ##############\n"
"	set w $win.mf\n"
"	frame $w -borderwidth 2 -relief groove\n"
"	pack $w -side top -fill both\n"
"\n"
"	## Fit buttons ###################\n"
"	set w $win.mf.fit\n"
"	frame $w\n"
"	pack $w -side left -fill x -ipadx 10\n"
"	button $w.fitone -width 10 -text \"Fit One\" -command {SetTzeroFromLinearFit \"one\"}\n"
"	button $w.fitsup -width 10 -text \"Fit Sup\" -command {SetTzeroFromLinearFit \"sup\"}\n"
"	button $w.fitall -width 10 -text \"Fit All\" -command {SetTzeroFromLinearFit \"all\"}\n"
"	#pack 	$w.fitone $w.fitsup $w.fitall -side top\n"
"	pack 	$w.fitone -side top\n"
"\n"
"	## Information labels ############\n"
"	set w $win.mf.info\n"
"	frame $w \n"
"	pack $w -side top -fill both\n"
"	label $w.integralfraction -text \"Integral Fraction : \" -anchor w\n"
"	label $w.tzero -text \"Tzero : \"  -anchor w\n"
"	label $w.initialtzero -text \"Initial Tzero : \"  -anchor w\n"
"	pack $w.integralfraction $w.tzero $w.initialtzero -side top -fill x\n"
"\n"
"	## Buttons #################\n"
"	set w $win.buttons\n"
"	frame $w\n"
"	pack $w -side bottom -fill x\n"
"	button $w.reset -text \"Reset\" -state disabled\n"
"	button $w.plotdoca -text \"Plot DOCA\" -command {PlotCalcDOCA}\n"
"        pack $w.plotdoca -side left -fill x\n"
"	pack $w.reset -side right\n"
"\n"
"        ## Misc Buttons #################\n"
"        ##  Added by Philip Coltharp, coltharp@jlab.org\n"
"	set w $win.misc\n"
"	frame $w\n"
"        button $w.tzerotable -text \"Tzero Table\" -command {TzeroTable}\n"
"        pack $w.tzerotable -side left \n"
"        pack $w -side bottom -fill x\n"
"\n"
"		\n"
"}\n"
"\n"
"proc NewTzeroPlotLimits {} {\n"
"\n"
"	global find_tzero_win\n"
"	global tzero_plot_min tzero_plot_max\n"
"	global replot\n"
"\n"
"	set w2 $find_tzero_win.limits.f.plotlimits\n"
"	set tzero_plot_min [$w2.min.en get]\n"
"	set tzero_plot_max [$w2.max.en get]\n"
"\n"
"	set replot 1\n"
"}\n"
"\n"
"proc NewTzeroFitLimits {} {\n"
"\n"
"	global find_tzero_win\n"
"	global tzero_fit_min tzero_fit_max\n"
"	global replot\n"
"\n"
"	set w2 $find_tzero_win.limits.f.fitlimits\n"
"	set tzero_fit_min [$w2.min.en get]\n"
"	set tzero_fit_max [$w2.max.en get]\n"
"\n"
"	set replot 1\n"
"}\n"
"\n"
"proc ShiftTzeroLimit {who delta} {\n"
"\n"
"	global find_tzero_win\n"
"	set w $find_tzero_win.limits.f.$who\n"
"	set val [$w.en get]\n"
"	$w.en delete 0 end\n"
"	$w.en insert 0 [expr $val+$delta]\n"
"\n"
"	NewTzeroFitLimits\n"
"	NewTzeroPlotLimits\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"

;
