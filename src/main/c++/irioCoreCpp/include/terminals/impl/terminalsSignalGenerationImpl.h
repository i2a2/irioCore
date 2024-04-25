#pragma once

#include <unordered_map>
#include <map>
#include <vector>

#include "terminals/impl/terminalsBaseImpl.h"

namespace irio {
/**
 * Class implementing the signal generation
 * functionality
 *
 * @ingroup Terminals
 */
class TerminalsSignalGenerationImpl: public TerminalsBaseImpl {
 public:
	TerminalsSignalGenerationImpl(
			ParserManager *parserManager,
			const NiFpga_Session &session,
			const Platform &platform);

	std::uint8_t getSGNoImpl() const;

	std::uint32_t getSGFrefImpl(const std::uint32_t n) const;

	std::vector<std::uint32_t> getVectorSGFrefsImpl() const;

	std::uint8_t getSGSignalTypeImpl(const std::uint32_t n) const;

	std::uint32_t getSGAmpImpl(const std::uint32_t n) const;

	std::uint32_t getSGFreqImpl(const std::uint32_t n) const;

	std::uint32_t getSGPhaseImpl(const std::uint32_t n) const;

	std::uint32_t getSGUpdateRateImpl(const std::uint32_t n) const;

	void setSGSignalTypeImpl(const std::uint32_t n,
							const std::uint8_t value) const;

	void setSGAmpImpl(const std::uint32_t n, const std::uint32_t value) const;

	void setSGFreqDecimationImpl(const std::uint32_t n, const std::uint32_t value) const;

	void setSGPhaseImpl(const std::uint32_t n, const std::uint32_t value) const;

	void setSGUpdateRateDecimationImpl(const std::uint32_t n,
							const std::uint32_t value) const;

 private:
	std::unordered_map<std::uint32_t, const std::uint32_t> m_mapSignalType_addr;
	std::unordered_map<std::uint32_t, const std::uint32_t> m_mapAmp_addr;
	std::unordered_map<std::uint32_t, const std::uint32_t> m_mapFreq_addr;
	std::unordered_map<std::uint32_t, const std::uint32_t> m_mapPhase_addr;
	std::unordered_map<std::uint32_t, const std::uint32_t> m_mapUpdateRate_addr;

	std::uint8_t m_numSG = 0;
	std::map<std::uint32_t, const std::uint32_t> m_mapFref;
};

}  // namespace irio

