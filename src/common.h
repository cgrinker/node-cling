#pragma once
#include <memory>


#pragma warning(push, 0)
#include <napi.h>

#include "cling/Interpreter/Value.h"
#include "cling/Interpreter/Interpreter.h"
#include "cling/MetaProcessor/MetaProcessor.h"
#include "cling/UserInterface/UserInterface.h"
#include "cling/Interpreter/Value.h"

#include "clang/Basic/LangOptions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/FrontendTool/Utils.h"

#include "llvm/Support/FileSystem.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/PrettyStackTrace.h"
#include "llvm/Support/Signals.h"

#pragma warning(pop)