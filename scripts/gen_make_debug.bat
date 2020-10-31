cd ..\Engine\scripts\
call gen_prj.bat
call make_debug.bat
cd ..\..\scripts\
cd ..\App\scripts\
call gen_prj.bat
call make_debug.bat
cd ..\..\scripts\

pause