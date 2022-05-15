
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name Laby121 -dir "C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby121/planAhead_run_3" -part xc3s500efg320-4
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "Laby12.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {Laby12.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top Laby12 $srcset
add_files [list {Laby12.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s500efg320-4
