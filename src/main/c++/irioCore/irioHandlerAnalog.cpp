#include "irioHandlerAnalog.h"

#include "irioInstanceManager.h"
#include "irioUtils.h"

using irio::errors::NiFpgaError;
using irio::errors::ResourceNotFoundError;

int irio_getAI(const irioDrv_t *p_DrvPvt, int n, int32_t *value,
			   TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		*value =
			getTerminalsAnalog(p_DrvPvt->DeviceSerialNumber, p_DrvPvt->session)
				.getAI(n);
	};

	return getOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_getAuxAI(const irioDrv_t *p_DrvPvt, int n, int32_t *value,
				  TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		*value = getTerminalsAuxAnalog(p_DrvPvt->DeviceSerialNumber,
									   p_DrvPvt->session)
					 .getAuxAI(n);
	};

	return getOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_getAuxAI_64(const irioDrv_t *p_DrvPvt, int n, int64_t *value,
					 TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		*value = getTerminalsAuxAnalog(p_DrvPvt->DeviceSerialNumber,
									   p_DrvPvt->session)
					 .getAuxAI64(n);
	};

	return getOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_getAO(const irioDrv_t *p_DrvPvt, int n, int32_t *value,
			   TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		*value =
			getTerminalsAnalog(p_DrvPvt->DeviceSerialNumber, p_DrvPvt->session)
				.getAO(n);
	};

	return getOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_getAuxAO(const irioDrv_t *p_DrvPvt, int n, int32_t *value,
				  TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		*value = getTerminalsAuxAnalog(p_DrvPvt->DeviceSerialNumber,
									   p_DrvPvt->session)
					 .getAuxAO(n);
	};

	return getOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_getAuxAO_64(const irioDrv_t *p_DrvPvt, int n, int64_t *value,
					 TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		*value = getTerminalsAuxAnalog(p_DrvPvt->DeviceSerialNumber,
									   p_DrvPvt->session)
					 .getAuxAO64(n);
	};

	return getOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_getAOEnable(const irioDrv_t *p_DrvPvt, int n, int32_t *value,
					 TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		*value =
			getTerminalsAnalog(p_DrvPvt->DeviceSerialNumber, p_DrvPvt->session)
				.getAOEnable(n);
	};

	return getOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_setAO(irioDrv_t *p_DrvPvt, int n, int32_t value, TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		getTerminalsAnalog(p_DrvPvt->DeviceSerialNumber, p_DrvPvt->session)
			.setAO(n, value);
	};

	return setOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_setAuxAO(irioDrv_t *p_DrvPvt, int n, int32_t value, TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		getTerminalsAuxAnalog(p_DrvPvt->DeviceSerialNumber, p_DrvPvt->session)
			.setAuxAO(n, value);
	};

	return setOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_setAuxAO_64(irioDrv_t *p_DrvPvt, int n, int64_t value,
					 TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		getTerminalsAuxAnalog(p_DrvPvt->DeviceSerialNumber, p_DrvPvt->session)
			.setAuxAO64(n, value);
	};

	return setOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_setAOEnable(irioDrv_t *p_DrvPvt, int n, int32_t value,
					 TStatus *status) {
	const auto f = [n, value, p_DrvPvt] {
		getTerminalsAnalog(p_DrvPvt->DeviceSerialNumber, p_DrvPvt->session)
			.setAOEnable(n, value);
	};

	return setOperationGeneric(f, status, p_DrvPvt->verbosity);
}

int irio_getNumAI(const irioDrv_t *p_DrvPvt, size_t *value, TStatus *status) {
	*value = p_DrvPvt->numAI;
	status->code = IRIO_success;
	return IRIO_success;
}

int irio_getNumAO(const irioDrv_t *p_DrvPvt, size_t *value, TStatus *status) {
	*value = p_DrvPvt->numAO;
	status->code = IRIO_success;
	return IRIO_success;
}

int irio_getNumAuxAI(const irioDrv_t *p_DrvPvt, size_t *value,
					 TStatus *status) {
	*value = p_DrvPvt->numAuxAI;
	status->code = IRIO_success;
	return IRIO_success;
}

int irio_getNumAuxAO(const irioDrv_t *p_DrvPvt, size_t *value,
					 TStatus *status) {
	*value = p_DrvPvt->numAuxAO;
	status->code = IRIO_success;
	return IRIO_success;
}

int irio_getNumAuxAI64(const irioDrv_t *p_DrvPvt, size_t *value,
					   TStatus *status) {
	*value = p_DrvPvt->numAuxAI64;
	status->code = IRIO_success;
	return IRIO_success;
}

int irio_getNumAuxAO64(const irioDrv_t *p_DrvPvt, size_t *value,
					   TStatus *status) {
	*value = p_DrvPvt->numAuxAI64;
	status->code = IRIO_success;
	return IRIO_success;
}
