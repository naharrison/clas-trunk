

char logo_tcl_proc[]=
"\n"
"global splash_win\n"
"\n"
"set splash_win 0\n"
"\n"
"# make sure main window isn't in the way\n"
"wm withdraw .\n"
"\n"
"proc dc3_splash {fname} {                                              \n"
"    global splash_win\n"
"\n"
"	 set splash_win .x\n"
"    toplevel $splash_win -bd 3 -relief raised\n"
"    wm withdraw $splash_win\n"
"    set sw [winfo screenwidth .]\n"
"    set sh [winfo screenheight .]\n"
"    image create photo \"splash\" -file \"$fname\"\n"
"    wm overrideredirect $splash_win 1\n"
"    label $splash_win.l -image splash -bd 1 -relief sunken\n"
"    pack $splash_win.l -side top -expand 1 -fill both\n"
"    set x [expr ($sw - 200)/2]\n"
"    set y [expr ($sh - 250)/2]\n"
"    wm geometry $splash_win +$x+$y\n"
"    wm deiconify $splash_win\n"
"    update idletasks\n"
"\n"
"    tkwait visibility $splash_win\n"
"    after 2500 {destroy $splash_win}\n"
"}\n"

;
