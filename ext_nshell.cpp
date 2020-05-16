#include "hphp/runtime/ext/extension.h"
#include "popen_noshell.h"
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>
#include <string>
using std::string;

namespace HPHP {
/////////////////////////////////////////////////////////////////////////////

Variant HHVM_FUNCTION(nshell_exec, const String& scmd) {
	FILE *fp;
	char buf[256];
	struct popen_noshell_pass_to_pclose pclose_arg;
	
	string returnData = "";
	
	int n = scmd.length();
	char cmd[n+1];
	
	strcpy(cmd, scmd.c_str());
	
	fp = popen_noshell_compat(cmd, "r", &pclose_arg);
	if (!fp) {
		return false;
	}

	while (fgets(buf, sizeof(buf)-1, fp)) {
		returnData = returnData + buf;
	}
	pclose_noshell(&pclose_arg);
	
	const String& hreturnData = returnData;
	
	return hreturnData;
}

class NshellExtension : public Extension {
 public:
  NshellExtension(): Extension("nshell", "1.0") {}

  void moduleInit() override {
    HHVM_FE(nshell_exec);

    loadSystemlib();
  }
} s_nshell_extension;

HHVM_GET_MODULE(nshell);

/////////////////////////////////////////////////////////////////////////////
} // namespace HPHP
