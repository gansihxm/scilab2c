// This file is released into the public domain

Directories = [ "ASTManagement", ...
                "CCodeGeneration", ...
                "ErrorMessages", ...
                "findDeps", ...
                "FunctionAnnotation", ...
                "FunctionList", ...
                "GeneralFunctions", ...
                "SymbolTable", ...
                "ToolInitialization", ...
<<<<<<< HEAD
                "Hardware/AVR", ...
                "Hardware/RasberryPi", ...
                "ImageProcessing", ...
=======
				        "Hardware/AVR", ...
				        "Hardware/RasberryPi", ...
				        "ImageProcessing", ...
>>>>>>> 9e5793a7b05b23e6044a6d7a9ddd5db39ba375f0
                "Scilab-Arduino"];


current_path_buildmacros = get_absolute_file_path("buildmacros.sce");

for K=1:size(Directories,"*")
  myfile = current_path_buildmacros + filesep() + Directories(K) + filesep() + "buildmacros.sce";
  if isfile(myfile) then
    exec(myfile);
  end
end

clear current_path_buildmacros;

tbx_build_macros(TOOLBOX_NAME, get_absolute_file_path('buildmacros.sce'));

clear tbx_build_macros;
