#include <gtest/gtest.h>
#include <iostream>
#include <limits>
#include <NiFpga.h>

#include "fixtures.h"
#include "fff_nifpga.h"

#include "irio_v2.h"
#include "errorsIrio.h"

#include "bfp.h"
#include "profiles/profileCPUDAQFlexRIO.h"
#include "terminals/names/namesTerminalsCommon.h"
#include "terminals/names/namesTerminalsFlexRIO.h"


using namespace iriov2;


class FlexRIOTests: public BaseTests {
public:
	FlexRIOTests():
			BaseTests("../../../resources/7966/NiFpga_FlexRIO_OnlyResources_7966.lvbitx")
	{
		setValueForReg(ReadFunctions::NiFpga_ReadU8,
						bfp.getRegister(TERMINAL_PLATFORM).address,
						PLATFORM_ID::FlexRIO);
		setValueForReg(ReadFunctions::NiFpga_ReadBool,
						bfp.getRegister(TERMINAL_RIOADAPTERCORRECT).address,
						1);
		setValueForReg(ReadFunctions::NiFpga_ReadU32,
						bfp.getRegister(TERMINAL_INSERTEDIOMODULEID).address,
						insertedIOModuleIDFake);
	}

	const uint32_t insertedIOModuleIDFake = 1234;
};

class ErrorFlexRIOTests: public FlexRIOTests {};


///////////////////////////////////////////////////////////////
///// FlexRIO Tests
///////////////////////////////////////////////////////////////
TEST_F(FlexRIOTests, TerminalsFlexRIO){
	IrioV2 irio(bitfilePath, "0", "V9.9");
	EXPECT_NO_THROW(irio.getTerminalsFlexRIO());
}

TEST_F(FlexRIOTests, RIOAdapterCorrect){
	IrioV2 irio(bitfilePath, "0", "V9.9");
	EXPECT_EQ(irio.getTerminalsFlexRIO().getRIOAdapterCorrect(), true);
}

TEST_F(FlexRIOTests, InsertedIOModuleID){
	IrioV2 irio(bitfilePath, "0", "V9.9");
	EXPECT_EQ(irio.getTerminalsFlexRIO().getInsertedIOModuleID(), insertedIOModuleIDFake);
}

///////////////////////////////////////////////////////////////
///// FlexRIO Error Tests
///////////////////////////////////////////////////////////////
TEST_F(ErrorFlexRIOTests, ModuleNotOKError) {
	setValueForReg(ReadFunctions::NiFpga_ReadBool,
			bfp.getRegister(TERMINAL_RIOADAPTERCORRECT).address, 0);
	IrioV2 irio(bitfilePath, "0", "V9.9");

	EXPECT_THROW(irio.startFPGA(100);,
		errors::ModulesNotOKError);
}

TEST_F(ErrorFlexRIOTests, cRIOTerminalNotImplementedError) {
	IrioV2 irio(bitfilePath, "0", "V9.9");

	EXPECT_THROW(irio.getTerminalsCRIO();,
		errors::TerminalNotImplementedError);
}
