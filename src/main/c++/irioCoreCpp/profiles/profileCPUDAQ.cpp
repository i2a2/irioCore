#include <profiles/profileCPUDAQ.h>
#include <terminals/terminalsDMADAQCPU.h>

namespace irio {

ProfileCPUDAQ::ProfileCPUDAQ(ParserManager *parserManager,
		const NiFpga_Session &session, const Platform &platform,
		const PROFILE_ID &id) :
		ProfileBase(parserManager, session, id) {
	addTerminal(TerminalsAnalog(parserManager, session, platform));
	addTerminal(TerminalsDigital(parserManager, session, platform));
	addTerminal(TerminalsAuxAnalog(parserManager, session, platform));
	addTerminal(TerminalsAuxDigital(parserManager, session, platform));
	addTerminal(TerminalsSignalGeneration(parserManager, session, platform));
	addTerminal(TerminalsDMADAQCPU(parserManager, session, platform));
}

}  // namespace irio
