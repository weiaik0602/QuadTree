##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=QuadTree
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/user1/Desktop/NgWa/QuadTree
ProjectPath            :=C:/Users/user1/Desktop/NgWa/QuadTree
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=user1
Date                   :=08/01/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="QuadTree.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_nodeHelper.c$(ObjectSuffix) $(IntermediateDirectory)/src_QuadTree.c$(ObjectSuffix) $(IntermediateDirectory)/test_test_QuadTree.c$(ObjectSuffix) $(IntermediateDirectory)/build_test_cache_test_QuadTree.c$(ObjectSuffix) $(IntermediateDirectory)/build_test_runners_test_QuadTree_runner.c$(ObjectSuffix) $(IntermediateDirectory)/build_test_preprocess_files_test_QuadTree.c$(ObjectSuffix) $(IntermediateDirectory)/build_test_preprocess_includes_test_QuadTree.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_vendor_unity_src_unity.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_vendor_c_exception_lib_CException.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_vendor_cmock_src_cmock.c$(ObjectSuffix) \
	$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-all.cc$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-main.cc$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_c.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_cpp.cpp$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_c.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_cpp.cpp$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_global_fakes.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_bar.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_display.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_event_processor.c$(ObjectSuffix) \
	$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_foo.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_event_processor.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_foo.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.cpp$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.fff.cpp$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_test_suite_template.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_ansic.c$(ObjectSuffix) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_cpp.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_subfolder_zzz.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_nodeHelper.c$(ObjectSuffix): src/nodeHelper.c $(IntermediateDirectory)/src_nodeHelper.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/src/nodeHelper.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_nodeHelper.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_nodeHelper.c$(DependSuffix): src/nodeHelper.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_nodeHelper.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_nodeHelper.c$(DependSuffix) -MM src/nodeHelper.c

$(IntermediateDirectory)/src_nodeHelper.c$(PreprocessSuffix): src/nodeHelper.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_nodeHelper.c$(PreprocessSuffix) src/nodeHelper.c

$(IntermediateDirectory)/src_QuadTree.c$(ObjectSuffix): src/QuadTree.c $(IntermediateDirectory)/src_QuadTree.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/src/QuadTree.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_QuadTree.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_QuadTree.c$(DependSuffix): src/QuadTree.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_QuadTree.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_QuadTree.c$(DependSuffix) -MM src/QuadTree.c

$(IntermediateDirectory)/src_QuadTree.c$(PreprocessSuffix): src/QuadTree.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_QuadTree.c$(PreprocessSuffix) src/QuadTree.c

$(IntermediateDirectory)/test_test_QuadTree.c$(ObjectSuffix): test/test_QuadTree.c $(IntermediateDirectory)/test_test_QuadTree.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/test/test_QuadTree.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_test_QuadTree.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_test_QuadTree.c$(DependSuffix): test/test_QuadTree.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_test_QuadTree.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_test_QuadTree.c$(DependSuffix) -MM test/test_QuadTree.c

$(IntermediateDirectory)/test_test_QuadTree.c$(PreprocessSuffix): test/test_QuadTree.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_test_QuadTree.c$(PreprocessSuffix) test/test_QuadTree.c

$(IntermediateDirectory)/build_test_cache_test_QuadTree.c$(ObjectSuffix): build/test/cache/test_QuadTree.c $(IntermediateDirectory)/build_test_cache_test_QuadTree.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/build/test/cache/test_QuadTree.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/build_test_cache_test_QuadTree.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/build_test_cache_test_QuadTree.c$(DependSuffix): build/test/cache/test_QuadTree.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/build_test_cache_test_QuadTree.c$(ObjectSuffix) -MF$(IntermediateDirectory)/build_test_cache_test_QuadTree.c$(DependSuffix) -MM build/test/cache/test_QuadTree.c

$(IntermediateDirectory)/build_test_cache_test_QuadTree.c$(PreprocessSuffix): build/test/cache/test_QuadTree.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/build_test_cache_test_QuadTree.c$(PreprocessSuffix) build/test/cache/test_QuadTree.c

$(IntermediateDirectory)/build_test_runners_test_QuadTree_runner.c$(ObjectSuffix): build/test/runners/test_QuadTree_runner.c $(IntermediateDirectory)/build_test_runners_test_QuadTree_runner.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/build/test/runners/test_QuadTree_runner.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/build_test_runners_test_QuadTree_runner.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/build_test_runners_test_QuadTree_runner.c$(DependSuffix): build/test/runners/test_QuadTree_runner.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/build_test_runners_test_QuadTree_runner.c$(ObjectSuffix) -MF$(IntermediateDirectory)/build_test_runners_test_QuadTree_runner.c$(DependSuffix) -MM build/test/runners/test_QuadTree_runner.c

$(IntermediateDirectory)/build_test_runners_test_QuadTree_runner.c$(PreprocessSuffix): build/test/runners/test_QuadTree_runner.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/build_test_runners_test_QuadTree_runner.c$(PreprocessSuffix) build/test/runners/test_QuadTree_runner.c

$(IntermediateDirectory)/build_test_preprocess_files_test_QuadTree.c$(ObjectSuffix): build/test/preprocess/files/test_QuadTree.c $(IntermediateDirectory)/build_test_preprocess_files_test_QuadTree.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/build/test/preprocess/files/test_QuadTree.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/build_test_preprocess_files_test_QuadTree.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/build_test_preprocess_files_test_QuadTree.c$(DependSuffix): build/test/preprocess/files/test_QuadTree.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/build_test_preprocess_files_test_QuadTree.c$(ObjectSuffix) -MF$(IntermediateDirectory)/build_test_preprocess_files_test_QuadTree.c$(DependSuffix) -MM build/test/preprocess/files/test_QuadTree.c

$(IntermediateDirectory)/build_test_preprocess_files_test_QuadTree.c$(PreprocessSuffix): build/test/preprocess/files/test_QuadTree.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/build_test_preprocess_files_test_QuadTree.c$(PreprocessSuffix) build/test/preprocess/files/test_QuadTree.c

$(IntermediateDirectory)/build_test_preprocess_includes_test_QuadTree.c$(ObjectSuffix): build/test/preprocess/includes/test_QuadTree.c $(IntermediateDirectory)/build_test_preprocess_includes_test_QuadTree.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/build/test/preprocess/includes/test_QuadTree.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/build_test_preprocess_includes_test_QuadTree.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/build_test_preprocess_includes_test_QuadTree.c$(DependSuffix): build/test/preprocess/includes/test_QuadTree.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/build_test_preprocess_includes_test_QuadTree.c$(ObjectSuffix) -MF$(IntermediateDirectory)/build_test_preprocess_includes_test_QuadTree.c$(DependSuffix) -MM build/test/preprocess/includes/test_QuadTree.c

$(IntermediateDirectory)/build_test_preprocess_includes_test_QuadTree.c$(PreprocessSuffix): build/test/preprocess/includes/test_QuadTree.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/build_test_preprocess_includes_test_QuadTree.c$(PreprocessSuffix) build/test/preprocess/includes/test_QuadTree.c

$(IntermediateDirectory)/vendor_ceedling_vendor_unity_src_unity.c$(ObjectSuffix): vendor/ceedling/vendor/unity/src/unity.c $(IntermediateDirectory)/vendor_ceedling_vendor_unity_src_unity.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/vendor/unity/src/unity.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_vendor_unity_src_unity.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_vendor_unity_src_unity.c$(DependSuffix): vendor/ceedling/vendor/unity/src/unity.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_vendor_unity_src_unity.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_vendor_unity_src_unity.c$(DependSuffix) -MM vendor/ceedling/vendor/unity/src/unity.c

$(IntermediateDirectory)/vendor_ceedling_vendor_unity_src_unity.c$(PreprocessSuffix): vendor/ceedling/vendor/unity/src/unity.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_vendor_unity_src_unity.c$(PreprocessSuffix) vendor/ceedling/vendor/unity/src/unity.c

$(IntermediateDirectory)/vendor_ceedling_vendor_c_exception_lib_CException.c$(ObjectSuffix): vendor/ceedling/vendor/c_exception/lib/CException.c $(IntermediateDirectory)/vendor_ceedling_vendor_c_exception_lib_CException.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/vendor/c_exception/lib/CException.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_vendor_c_exception_lib_CException.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_vendor_c_exception_lib_CException.c$(DependSuffix): vendor/ceedling/vendor/c_exception/lib/CException.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_vendor_c_exception_lib_CException.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_vendor_c_exception_lib_CException.c$(DependSuffix) -MM vendor/ceedling/vendor/c_exception/lib/CException.c

$(IntermediateDirectory)/vendor_ceedling_vendor_c_exception_lib_CException.c$(PreprocessSuffix): vendor/ceedling/vendor/c_exception/lib/CException.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_vendor_c_exception_lib_CException.c$(PreprocessSuffix) vendor/ceedling/vendor/c_exception/lib/CException.c

$(IntermediateDirectory)/vendor_ceedling_vendor_cmock_src_cmock.c$(ObjectSuffix): vendor/ceedling/vendor/cmock/src/cmock.c $(IntermediateDirectory)/vendor_ceedling_vendor_cmock_src_cmock.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/vendor/cmock/src/cmock.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_vendor_cmock_src_cmock.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_vendor_cmock_src_cmock.c$(DependSuffix): vendor/ceedling/vendor/cmock/src/cmock.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_vendor_cmock_src_cmock.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_vendor_cmock_src_cmock.c$(DependSuffix) -MM vendor/ceedling/vendor/cmock/src/cmock.c

$(IntermediateDirectory)/vendor_ceedling_vendor_cmock_src_cmock.c$(PreprocessSuffix): vendor/ceedling/vendor/cmock/src/cmock.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_vendor_cmock_src_cmock.c$(PreprocessSuffix) vendor/ceedling/vendor/cmock/src/cmock.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-all.cc$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-all.cc $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-all.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-all.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-all.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-all.cc$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-all.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-all.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-all.cc$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-all.cc

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-all.cc$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-all.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-all.cc$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-all.cc

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-main.cc$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-main.cc $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-main.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-main.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-main.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-main.cc$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-main.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-main.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-main.cc$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-main.cc

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-main.cc$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-main.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_gtest_gtest-main.cc$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/gtest/gtest-main.cc

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_c.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_c.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_c.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_c.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_c.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_c.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_c.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_c.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_c.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_c.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_c.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_c.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_c.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_c.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_cpp.cpp$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_cpp.cpp $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_cpp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_cpp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_cpp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_cpp.cpp$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_cpp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_cpp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_cpp.cpp$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_cpp.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_cpp.cpp$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_cpp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_cpp.cpp$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_cpp.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_c.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_c.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_c.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_c.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_c.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_c.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_c.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_c.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_c.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_c.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_c.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_c.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_c.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_c.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_cpp.cpp$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_cpp.cpp $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_cpp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_cpp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_cpp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_cpp.cpp$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_cpp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_cpp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_cpp.cpp$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_cpp.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_cpp.cpp$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_cpp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_fff_test_global_cpp.cpp$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/fff_test_global_cpp.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_global_fakes.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/global_fakes.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_global_fakes.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/global_fakes.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_global_fakes.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_global_fakes.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/global_fakes.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_global_fakes.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_global_fakes.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/global_fakes.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_global_fakes.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/global_fakes.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_test_global_fakes.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/test/global_fakes.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_bar.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/bar.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_bar.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/bar.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_bar.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_bar.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/bar.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_bar.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_bar.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/bar.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_bar.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/bar.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_bar.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/bar.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_display.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/display.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_display.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/display.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_display.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_display.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/display.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_display.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_display.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/display.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_display.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/display.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_display.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/display.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_event_processor.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/event_processor.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_event_processor.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/event_processor.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_event_processor.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_event_processor.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/event_processor.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_event_processor.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_event_processor.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/event_processor.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_event_processor.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/event_processor.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_event_processor.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/event_processor.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_foo.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/foo.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_foo.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/foo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_foo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_foo.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/foo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_foo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_foo.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/foo.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_foo.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/foo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_foo.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/foo.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_event_processor.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_event_processor.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_event_processor.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_event_processor.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_event_processor.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_event_processor.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_event_processor.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_event_processor.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_event_processor.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_event_processor.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_event_processor.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_event_processor.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_event_processor.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_event_processor.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_foo.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_foo.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_foo.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_foo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_foo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_foo.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_foo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_foo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_foo.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_foo.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_foo.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_foo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_test_test_foo.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/examples/fff_example/test/test_foo.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.cpp$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.cpp $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.cpp$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.cpp$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.cpp$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.cpp$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.fff.cpp$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.fff.cpp $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.fff.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.fff.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.fff.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.fff.cpp$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.fff.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.fff.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.fff.cpp$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.fff.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.fff.cpp$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.fff.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_driver_testing_driver.test.fff.cpp$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/driver_testing/driver.test.fff.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_test_suite_template.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/test_suite_template.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_test_suite_template.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/test_suite_template.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_test_suite_template.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_test_suite_template.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/test_suite_template.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_test_suite_template.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_test_suite_template.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/test_suite_template.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_test_suite_template.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/test_suite_template.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_test_suite_template.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/test_suite_template.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_ansic.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_ansic.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_ansic.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_ansic.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_ansic.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_ansic.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_ansic.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_ansic.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_ansic.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_ansic.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_ansic.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_ansic.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_ansic.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_ansic.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_cpp.cpp$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_cpp.cpp $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_cpp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_cpp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_cpp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_cpp.cpp$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_cpp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_cpp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_cpp.cpp$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_cpp.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_cpp.cpp$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_cpp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_vendor_fff_examples_embedded_ui_UI_test_cpp.cpp$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/vendor/fff/examples/embedded_ui/UI_test_cpp.cpp

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_subfolder_zzz.c$(ObjectSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/subfolder/zzz.c $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_subfolder_zzz.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/user1/Desktop/NgWa/QuadTree/vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/subfolder/zzz.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_subfolder_zzz.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_subfolder_zzz.c$(DependSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/subfolder/zzz.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_subfolder_zzz.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_subfolder_zzz.c$(DependSuffix) -MM vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/subfolder/zzz.c

$(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_subfolder_zzz.c$(PreprocessSuffix): vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/subfolder/zzz.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vendor_ceedling_plugins_fake_function_framework_examples_fff_example_src_subfolder_zzz.c$(PreprocessSuffix) vendor/ceedling/plugins/fake_function_framework/examples/fff_example/src/subfolder/zzz.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


