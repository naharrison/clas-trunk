

char caldb_tcl_proc[]=
"#!/usr/bin/wish -f\n"
"\n"
"\n"
"set usercomment \"\"\n"
"\n"
"# These defaults are overwritten from C in LinkTclToC()\n"
"set caldb_host      \"clasdb.jlab.org\"\n"
"set caldb_runindex  \"calib_user.RunIndexDavidL\"\n"
"set caldb_user      \"davidl\"\n"
"set caldb_password  \"\"\n"
"\n"
"set minrun 0\n"
"set maxrun 0\n"
"\n"
"set boldfont    \"-*-times-bold-o-*-*-10-*-*-*-*-*-*-*\"\n"
"\n"
"proc caldb_init {path} {\n"
"\n"
"   global caldb_path\n"
"   global caldb_host caldb_runindex caldb_user caldb_password\n"
"   global runnumber minrun maxrun\n"
"   global boldfont\n"
"\n"
"   set caldb_path $path\n"
"   \n"
"   ######## checkbuttons #######\n"
"   set win $caldb_path.buttons\n"
"   frame $win -relief groove -borderwidth 3\n"
"   pack $win -side top -fill both\n"
"\n"
"   ######## Write buttons ######\n"
"   set win $caldb_path.controls\n"
"   frame $win\n"
"   pack $win -side bottom -fill both -pady 3\n"
"   button $win.map  -text \"Write to Database\" -command {CaldbWrite}\n"
"   pack $win.map\n"
"\n"
"   ####### Frame for caldb info and run numbers #######\n"
"   set win $caldb_path.ri\n"
"   frame $win -relief groove -borderwidth 2\n"
"   pack $win -side top -fill both -pady 10\n"
"   \n"
"   ######### RunNumbers ###########\n"
"   set win $caldb_path.ri.run\n"
"   frame $win -relief groove -borderwidth 2\n"
"   pack $win -side left -fill both -ipady 3\n"
"\n"
"   frame $win.run\n"
"   label $win.run.lab -text \"Run Number:\"\n"
"   label $win.run.num -textvariable runnumber\n"
"   pack $win.run.lab $win.run.num -side left -fill x\n"
"\n"
"   frame $win.minrun\n"
"   label $win.minrun.lab -text \"Min. Run Num.:\"\n"
"   entry $win.minrun.en -width 10 -textvariable minrun\n"
"   pack $win.minrun.lab $win.minrun.en -side left -fill x\n"
"\n"
"   frame $win.maxrun\n"
"   label $win.maxrun.lab -text \"Max. Run Num.:\"\n"
"   entry $win.maxrun.en -width 10 -textvariable maxrun\n"
"   pack $win.maxrun.lab $win.maxrun.en -side left -fill x\n"
"\n"
"   pack $win.run $win.minrun $win.maxrun -side top \n"
"\n"
"   ######### Database info ###########\n"
"   set win $caldb_path.ri.dbi\n"
"   frame $win -relief groove -borderwidth 2\n"
"   pack $win -side right -fill x -ipady 3\n"
"\n"
"   label $win.title -text \"Database Info.\"\n"
"   pack $win.title -side top -fill x\n"
"\n"
"	frame $win.info\n"
"   pack $win.info -side top -fill x\n"
"   frame $win.info.labs\n"
"   frame $win.info.vals\n"
"   pack $win.info.labs $win.info.vals -side left\n"
"   \n"
"   label $win.info.labs.host		-anchor e -text \"HOST:\"\n"
"   label $win.info.vals.host		-anchor w -textvariable caldb_host\n"
"   \n"
"   label $win.info.labs.runindex	-anchor e -text \"RUNINDEX:\"\n"
"   label $win.info.vals.runindex	-anchor w -textvariable caldb_runindex\n"
"   \n"
"   label $win.info.labs.user		-anchor e -text \"USER:\"\n"
"   label $win.info.vals.user		-anchor w -textvariable caldb_user\n"
"   \n"
"   label $win.info.labs.password	-anchor e -text \"PASSWORD:\"\n"
"   label $win.info.vals.password	-anchor w -text \"\"\n"
"#   label $win.info.vals.password	-anchor w -textvariable caldb_password\n"
"\n"
"	pack $win.info.labs.host $win.info.labs.runindex $win.info.labs.user $win.info.labs.password -side top -fill x\n"
"	pack $win.info.vals.host $win.info.vals.runindex $win.info.vals.user $win.info.vals.password -side top -fill x\n"
"\n"
"   button $win.mod -text \"Modify\" -width 10 -command {ModifyDBInfo}\n"
"   pack $win.mod -side bottom\n"
"\n"
"   ####### Frame for defaults and misc #######\n"
"   set win $caldb_path.misc\n"
"   frame $win -relief groove -borderwidth 2\n"
"   pack $win -side top -fill both -pady 10\n"
"\n"
"   ####### Defaults #########\n"
"   set win $caldb_path.misc.def\n"
"   frame $win -relief groove -borderwidth 2\n"
"   pack $win -side left -fill both -ipady 3\n"
"	button $win.settodef -text \"Set to Defaults\" -command {SetDefaults 1}\n"
"	pack $win.settodef -side top -fill x\n"
"	button $win.setalltodef -text \"Set All to Defaults\" -command {SetAllDefaults}\n"
"	pack $win.setalltodef -side top -fill x\n"
"}\n"
"\n"
"proc UpdateMinMaxRun {var val} {\n"
"	global caldb_path minrun maxrun\n"
"\n"
"	$caldb_path.ri.run.$var.en delete 0 end\n"
"	$caldb_path.ri.run.$var.en insert 0 $val\n"
"}\n"
"\n"
"proc ModifyDBInfo {} {\n"
"	global changedbinfowin\n"
"	global mdbi_result\n"
"   global caldb_host caldb_runindex caldb_user caldb_password\n"
"   \n"
"   set changedbinfowin .changedbinfo\n"
"   toplevel $changedbinfowin\n"
"\n"
"	### Title ###\n"
"	set win $changedbinfowin\n"
"	label $win.title -text \"Modify DB Access Info.\"\n"
"	pack $win.title -side top -fill x\n"
"	wm title $changedbinfowin \"dc3: Modifying Database Access Information\"\n"
"\n"
"	### Information ###\n"
"	frame $win.info -relief groove -borderwidth 3\n"
"   pack $win.info -side top -fill x\n"
"   frame $win.info.labs\n"
"   frame $win.info.vals\n"
"   pack $win.info.labs $win.info.vals -side left\n"
"   \n"
"   label $win.info.labs.host		-anchor e -text \"HOST:\"\n"
"   entry $win.info.vals.host		-width 40\n"
"   $win.info.vals.host insert 0 $caldb_host\n"
"   \n"
"   label $win.info.labs.runindex	-anchor e -text \"RUNINDEX:\"\n"
"   entry $win.info.vals.runindex	-width 40\n"
"   $win.info.vals.runindex insert 0 $caldb_runindex\n"
"   \n"
"   label $win.info.labs.user		-anchor e -text \"USER:\"\n"
"   entry $win.info.vals.user		-width 40\n"
"   $win.info.vals.user insert 0 $caldb_user\n"
"   \n"
"   label $win.info.labs.password	-anchor e -text \"PASSWORD:\"\n"
"   entry $win.info.vals.password	-width 40 -show *\n"
"   $win.info.vals.password insert 0 $caldb_password\n"
"\n"
"	pack $win.info.labs.host $win.info.labs.runindex $win.info.labs.user $win.info.labs.password -side top -fill x\n"
"	pack $win.info.vals.host $win.info.vals.runindex $win.info.vals.user $win.info.vals.password -side top -fill x\n"
"\n"
"	### OK and Cancel buttons ###\n"
"	frame $win.buttons\n"
"	pack $win.buttons -side bottom -fill x\n"
"	button $win.buttons.ok -text \"OK\" -command {set mdbi_result 1}\n"
"	pack $win.buttons.ok -side right\n"
"	button $win.buttons.cancel -text \"Cancel\" -command {set mdbi_result 0}\n"
"	pack $win.buttons.cancel -side left\n"
"\n"
"   set mdbi_result 0\n"
"   CenterWindow $changedbinfowin\n"
"   tkwait variable mdbi_result\n"
"\n"
"   if [expr $mdbi_result==1] {\n"
"		set caldb_host			[$win.info.vals.host get		]\n"
"		set caldb_runindex	[$win.info.vals.runindex get	]\n"
"		set caldb_user			[$win.info.vals.user get		]\n"
"		set caldb_password	[$win.info.vals.password get	]\n"
"   }\n"
"\n"
"   destroy $changedbinfowin\n"
"}\n"
"\n"
"proc NewMapFile {} {\n"
"\n"
"   global mapfile\n"
"\n"
"   set types {\n"
"      {{Map files} {.map} }\n"
"      {{All files} *      }\n"
"   }\n"
"   \n"
"   set fname [tk_getOpenFile -filetypes $types -title \"Select new DC_DOCA.map file\"]\n"
"   \n"
"   if {$fname!=\"\"} {\n"
"      set mapfile $fname\n"
"   }\n"
"}\n"
"\n"
"proc GetPassword {} {\n"
"   \n"
"   global passwin passwd\n"
"\n"
"   set passwd \"\"\n"
"\n"
"   set passwin .passwin\n"
"   toplevel $passwin\n"
"   wm title $passwin \"Expert Password\"\n"
"   \n"
"   label $passwin.mess1 -text \"Some values were obtained while in\"\n"
"   label $passwin.mess2 -text \"expert mode. Please enter the expert\"\n"
"   label $passwin.mess3 -text \"mode password.\"\n"
"   pack $passwin.mess1 $passwin.mess2 $passwin.mess3 -side top -fill both\n"
"   \n"
"   set win $passwin.pass\n"
"   frame $win -relief groove -borderwidth 3\n"
"   pack $win -side top -fill x\n"
"   label $win.lab -text \"Password:\"\n"
"   entry $win.en -width 20 -show *\n"
"   bind $win.en <Return> {$passwin.buttons.ok invoke}\n"
"   pack $win.lab $win.en -side left -fill x\n"
"   \n"
"   set win $passwin.buttons\n"
"   frame $win -relief groove -borderwidth 3\n"
"   pack $win -side bottom -fill x\n"
"   button $win.ok -text \"OK\" -command {\\n"
"      set passwd [$passwin.pass.en get]; \\n"
"      destroy $passwin;\\n"
"   }\n"
"   button $win.cancel -text \"Cancel\" -command {destroy $passwin}\n"
"   pack $win.ok -side left\n"
"   pack $win.cancel -side right\n"
"   CenterWindow $passwin\n"
"   tkwait window $passwin\n"
"   \n"
"   return $passwd\n"
"}\n"
"\n"
"\n"
"proc AdditionalComments {} {\n"
"\n"
"   global usercomment\n"
"   global commentswin\n"
"   global ac_result\n"
"   \n"
"   set commentswin .comments\n"
"   toplevel $commentswin\n"
"\n"
"   set win $commentswin\n"
"   label $win.lab -text \"Please enter any additional comments\"\n"
"   pack $win.lab -side top\n"
"   \n"
"   text $win.text -height 5 -width 40\n"
"   $win.text insert end $usercomment\n"
"   pack $win.text -side top -fill both\n"
"   focus $win.text\n"
"\n"
"   set win $commentswin.buttons\n"
"   frame $win\n"
"   pack $win -side bottom -fill both\n"
"   button $win.ok -text \"OK\" -command {set ac_result \"OK\"}\n"
"   button $win.cancel -text \"Cancel\" -command {set ac_result \"Cancel\"}\n"
"   pack $win.ok -side left\n"
"   pack $win.cancel -side right\n"
"\n"
"   set ac_result \"None\"\n"
"   CenterWindow $commentswin\n"
"   tkwait variable ac_result\n"
"   \n"
"   set usercomment [$commentswin.text get 1.0 end]\n"
"   destroy $commentswin\n"
"   \n"
"   return $ac_result\n"
"}\n"
"\n"
"#\n"
"# OK, we need to be careful here. There is a C routine linked to a Tcl\n"
"# routine called \"SetParametersToDefault\" that we will call from here.\n"
"# That routine sets parameters in the \"Additional Expert Controls\" \n"
"# window to the defaults for whatever function type is currently\n"
"# specified.\n"
"#\n"
"# 	This routine will make sure the \"Additional Expert Controls\"\n"
"# window is open, select the \"Power\" X vs. T function type and \"Mac\"\n"
"# timewalk types, invoke the \"Defaults\" buttons (which, in turn, will\n"
"# call \"SetParametersToDefault\"). After that, it will invoke the \n"
"# \"ApplyExpertParameters\" buttons to copy the values from the \"Additional\n"
"# Expert Controls\" window into the appropriate C data structures.\n"
"# Whew! \n"
"proc SetDefaults {close_aec} {\n"
"	global options_path\n"
"	global expert_controls\n"
"\n"
"	# Open \"Additional Expert Controls\" window\n"
"	invokeButton $options_path.aec\n"
"\n"
"	# Select \"Mac\" timewalk type and \"Power\" X vs. T type\n"
"	.expert_controls.timewalk.tf.twmenu.m	invoke 3 ; SetTWType 0 0 0\n"
"	.expert_controls.xvst.tf.xvstmenu.m		invoke 3 ; SetXvsTType 0 0 0\n"
"\n"
"	#### Here, we Set and apply the default parameters. It would be nice\n"
"	#### if we did this via inoking the buttons, but it takes significantly\n"
"	#### longer to do it that way. We also use the \"bypass_warning\" and\n"
"	#### \"bypass_histo_refill\" flags here to help speed things up.\n"
"\n"
"	# Set values in A.E.C. window to defaults.\n"
"	.expert_controls.timewalk.but.defaults flash\n"
"	SetParametersToDefault timewalk xvst bypass_warning\n"
"	.expert_controls.xvst.but.defaults flash\n"
"	\n"
"	# Copy parameters from A.E.C window to C data structure\n"
"	.expert_controls.timewalk.but.apply flash\n"
"	ApplyExpertParameters timewalk xvst bypass_histo_refill\n"
"	.expert_controls.xvst.but.apply flash\n"
"	\n"
"	# Optionally close \"Additional Expert Controls\" window\n"
"	if {[expr $close_aec!=0]} {.expert_controls.dismiss invoke}\n"
"}\n"
"\n"
"\n"
"#\n"
"# Call the above routine for all sup/sec\n"
"#\n"
"proc SetAllDefaults {} {\n"
"	global sec sup\n"
"   \n"
"   set save_sec $sec\n"
"   set save_sup $sup\n"
"      \n"
"   for {set sup 1} {[expr $sup<7]} {incr sup} {\n"
"      for {set sec 1} {[expr $sec<7]} {incr sec} {\n"
"         update\n"
"         SetDefaults 0\n"
"      }\n"
"      set sec 6\n"
"   }\n"
"   \n"
"   set sup $save_sup\n"
"   set sec $save_sec\n"
"}\n"
"\n"
"\n"
"\n"
"\n"

;

