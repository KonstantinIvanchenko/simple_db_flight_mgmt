##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cpp_db_prj
ConfigurationName      :=Debug
WorkspacePath          :=/home/konstiva/opt/cpp_db/cpp_db
ProjectPath            :=/home/konstiva/opt/cpp_db/cpp_db/cpp_db_prj
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Konstantin
Date                   :=08/02/20
CodeLitePath           :=/home/konstiva/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
ObjectsFileList        :="cpp_db_prj.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)opt/cpp_db/cpp_db/cpp_db_prj/include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mysqlcppconn 
ArLibs                 :=  "libmysqlcppconn.so" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/x86_64-linux-gnu/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/db_mgmt.cpp$(ObjectSuffix) $(IntermediateDirectory)/flights_db.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/konstiva/opt/cpp_db/cpp_db/cpp_db_prj/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/db_mgmt.cpp$(ObjectSuffix): db_mgmt.cpp $(IntermediateDirectory)/db_mgmt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/konstiva/opt/cpp_db/cpp_db/cpp_db_prj/db_mgmt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/db_mgmt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/db_mgmt.cpp$(DependSuffix): db_mgmt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/db_mgmt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/db_mgmt.cpp$(DependSuffix) -MM db_mgmt.cpp

$(IntermediateDirectory)/db_mgmt.cpp$(PreprocessSuffix): db_mgmt.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/db_mgmt.cpp$(PreprocessSuffix) db_mgmt.cpp

$(IntermediateDirectory)/flights_db.cpp$(ObjectSuffix): flights_db.cpp $(IntermediateDirectory)/flights_db.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/konstiva/opt/cpp_db/cpp_db/cpp_db_prj/flights_db.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/flights_db.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/flights_db.cpp$(DependSuffix): flights_db.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/flights_db.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/flights_db.cpp$(DependSuffix) -MM flights_db.cpp

$(IntermediateDirectory)/flights_db.cpp$(PreprocessSuffix): flights_db.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/flights_db.cpp$(PreprocessSuffix) flights_db.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


