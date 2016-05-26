//
// sdaccel(TM)
// rundef.js: a sdaccel-generated Runs Script for WSH 5.1/5.6
// Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
//

echo "This script was generated under a different operating system."
echo "Please update the PATH variable below, before executing this script"
exit

var WshShell = new ActiveXObject( "WScript.Shell" );
var ProcEnv = WshShell.Environment( "Process" );
var PathVal = ProcEnv("PATH");
if ( PathVal.length == 0 ) {
  PathVal = "/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/bin;/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/Vivado_HLS/bin;";
} else {
  PathVal = "/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/bin;/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/Vivado_HLS/bin;" + PathVal;
}

ProcEnv("PATH") = PathVal;

var RDScrFP = WScript.ScriptFullName;
var RDScrN = WScript.ScriptName;
var RDScrDir = RDScrFP.substr( 0, RDScrFP.length - RDScrN.length - 1 );
var ISEJScriptLib = RDScrDir + "/ISEWrap.js";
eval( EAInclude(ISEJScriptLib) );


ISEStep( "vivado_hls",
         "-f krnl_sobel.tcl" );



function EAInclude( EAInclFilename ) {
  var EAFso = new ActiveXObject( "Scripting.FileSystemObject" );
  var EAInclFile = EAFso.OpenTextFile( EAInclFilename );
  var EAIFContents = EAInclFile.ReadAll();
  EAInclFile.Close();
  return EAIFContents;
}
