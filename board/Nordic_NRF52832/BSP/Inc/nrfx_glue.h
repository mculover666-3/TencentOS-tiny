/*
 * Copyright (c) 2017 - 2018, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NRFX_GLUE_H__
#define NRFX_GLUE_H__

// THIS IS A TEMPLATE FILE.
// It should be copied to a suitable location within the host environment into
// which nrfx is integrated, and the following macros should be provided with
// appropriate implementations.
// And this comment should be removed from the customized file.

#ifdef __cplusplus
extern "C" {
#endif

#include "apply_old_config.h"

int NVIC_IRQ_IS_ENABLED(unsigned int irq);
unsigned int nrfx_enter_critical(void);
void nrfx_exit_critical(unsigned int ctx);

/**
 * @defgroup nrfx_glue nrfx_glue.h
 * @{
 * @ingroup nrfx
 *
 * @brief This file contains macros that should be implemented according to
 *        the needs of the host environment into which @em nrfx is integrated.
 */

// Uncomment this line to use the standard MDK way of binding IRQ handlers
// at linking time.
//#include <soc/nrfx_irqs.h>

//------------------------------------------------------------------------------

#include <nrf_assert.h>
/**
 * @brief Macro for placing a runtime assertion.
 *
 * @param expression  Expression to evaluate.
 */
#define NRFX_ASSERT(expression)     ASSERT(expression)

/**
 * @brief Macro for placing a compile time assertion.
 *
 * @param expression  Expression to evaluate.
 */
#define NRFX_STATIC_ASSERT(expression)

//------------------------------------------------------------------------------

/**
 * @brief Macro for setting the priority of a specific IRQ.
 *
 * @param irq_number  IRQ number.
 * @param priority    Priority to set.
 */
#define NRFX_IRQ_PRIORITY_SET(irq_number, priority) NVIC_SetPriority(irq_number, priority)

/**
 * @brief Macro for enabling a specific IRQ.
 *
 * @param irq_number  IRQ number.
 */
#define NRFX_IRQ_ENABLE(irq_number) NVIC_EnableIRQ(irq_number)

/**
 * @brief Macro for checking if a specific IRQ is enabled.
 *
 * @param irq_number  IRQ number.
 *
 * @retval true  If the IRQ is enabled.
 * @retval false Otherwise.
 */
#define NRFX_IRQ_IS_ENABLED(irq_number) NVIC_IRQ_IS_ENABLED(irq_number)

/**
 * @brief Macro for disabling a specific IRQ.
 *
 * @param irq_number  IRQ number.
 */
#define NRFX_IRQ_DISABLE(irq_number) NVIC_DisableIRQ(irq_number)

/**
 * @brief Macro for setting a specific IRQ as pending.
 *
 * @param irq_number  IRQ number.
 */
#define NRFX_IRQ_PENDING_SET(irq_number) NVIC_SetPendingIRQ(irq_number)

/**
 * @brief Macro for clearing the pending status of a specific IRQ.
 *
 * @param irq_number  IRQ number.
 */
#define NRFX_IRQ_PENDING_CLEAR(irq_number) NVIC_ClearPendingIRQ(irq_number)

/**
 * @brief Macro for checking the pending status of a specific IRQ.
 *
 * @retval true  If the IRQ is pending.
 * @retval false Otherwise.
 */
#define NRFX_IRQ_IS_PENDING(irq_number) NVIC_GetPendingIRQ(irq_number)

/**
 * @brief Macro for entering into a critical section.
 */
#define NRFX_CRITICAL_SECTION_ENTER() {unsigned int ctx; ctx = nrfx_enter_critical();

/**
 * @brief Macro for exiting from a critical section.
 */
#define NRFX_CRITICAL_SECTION_EXIT() nrfx_exit_critical(ctx);}

//------------------------------------------------------------------------------

/**
 * @brief When set to a non-zero value, this macro specifies that
 *        @ref nrfx_coredep_delay_us uses a precise DWT-based solution.
 *        A compilation error is generated if the DWT unit is not present
 *        in the SoC used.
 */
#define NRFX_DELAY_DWT_BASED    0

/**
 * @brief Macro for delaying the code execution for at least the specified time.
 *
 * @param us_time Number of microseconds to wait.
 */
#define NRFX_DELAY_US(us_time)

//------------------------------------------------------------------------------

/**
 * @brief Atomic 32-bit unsigned type.
 */
#define nrfx_atomic_t

/**
 * @brief Macro for storing a value to an atomic object and returning its previous value.
 *
 * @param[in] p_data  Atomic memory pointer.
 * @param[in] value   Value to store.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_STORE(p_data, value)

/**
 * @brief Macro for running a bitwise OR operation on an atomic object and returning its previous value.
 *
 * @param[in] p_data  Atomic memory pointer.
 * @param[in] value   Value of the second operand in the OR operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_OR(p_data, value)

/**
 * @brief Macro for running a bitwise AND operation on an atomic object
 *        and returning its previous value.
 *
 * @param[in] p_data  Atomic memory pointer.
 * @param[in] value   Value of the second operand in the AND operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_AND(p_data, value)

/**
 * @brief Macro for running a bitwise XOR operation on an atomic object
 *        and returning its previous value.
 *
 * @param[in] p_data  Atomic memory pointer.
 * @param[in] value   Value of the second operand in the XOR operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_XOR(p_data, value)

/**
 * @brief Macro for running an addition operation on an atomic object
 *        and returning its previous value.
 *
 * @param[in] p_data  Atomic memory pointer.
 * @param[in] value   Value of the second operand in the ADD operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_ADD(p_data, value)

/**
 * @brief Macro for running a subtraction operation on an atomic object
 *        and returning its previous value.
 *
 * @param[in] p_data  Atomic memory pointer.
 * @param[in] value   Value of the second operand in the SUB operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_SUB(p_data, value)

//------------------------------------------------------------------------------
#ifndef NRFX_CUSTOM_ERROR_CODES

#include <sdk_errors.h>
/**
 * @brief When set to a non-zero value, this macro specifies that the
 *        @ref nrfx_error_codes and the @ref ret_code_t type itself are defined
 *        in a customized way and the default definitions from @c <nrfx_error.h>
 *        should not be used.
 */
#define NRFX_CUSTOM_ERROR_CODES 1

typedef ret_code_t nrfx_err_t;

#define NRFX_SUCCESS                    NRF_SUCCESS
#define NRFX_ERROR_INTERNAL             NRF_ERROR_INTERNAL
#define NRFX_ERROR_NO_MEM               NRF_ERROR_NO_MEM
#define NRFX_ERROR_NOT_SUPPORTED        NRF_ERROR_NOT_SUPPORTED
#define NRFX_ERROR_INVALID_PARAM        NRF_ERROR_INVALID_PARAM
#define NRFX_ERROR_INVALID_STATE        NRF_ERROR_INVALID_STATE
#define NRFX_ERROR_INVALID_LENGTH       NRF_ERROR_INVALID_LENGTH
#define NRFX_ERROR_TIMEOUT              NRF_ERROR_TIMEOUT
#define NRFX_ERROR_FORBIDDEN            NRF_ERROR_FORBIDDEN
#define NRFX_ERROR_NULL                 NRF_ERROR_NULL
#define NRFX_ERROR_INVALID_ADDR         NRF_ERROR_INVALID_ADDR
#define NRFX_ERROR_BUSY                 NRF_ERROR_BUSY
#define NRFX_ERROR_ALREADY_INITIALIZED  NRF_ERROR_MODULE_ALREADY_INITIALIZED

#define NRFX_ERROR_DRV_TWI_ERR_OVERRUN  NRF_ERROR_DRV_TWI_ERR_OVERRUN
#define NRFX_ERROR_DRV_TWI_ERR_ANACK    NRF_ERROR_DRV_TWI_ERR_ANACK
#define NRFX_ERROR_DRV_TWI_ERR_DNACK    NRF_ERROR_DRV_TWI_ERR_DNACK

#endif // NRFX_CUSTOM_ERROR_CODES
//------------------------------------------------------------------------------

/**
 * @brief Bitmask defining DPPI channels reserved to be used outside of nrfx.
 */
#define NRFX_DPPI_CHANNELS_USED  0

/**
 * @brief Bitmask defining DPPI groups reserved to be used outside of nrfx.
 */
#define NRFX_DPPI_GROUPS_USED    0

/**
 * @brief Bitmask defining PPI channels reserved to be used outside of nrfx.
 */
#define NRFX_PPI_CHANNELS_USED  0

/**
 * @brief Bitmask defining PPI groups reserved to be used outside of nrfx.
 */
#define NRFX_PPI_GROUPS_USED    0

/**
 * @brief Bitmask defining SWI instances reserved to be used outside of nrfx.
 */
#define NRFX_SWI_USED           0

/**
 * @brief Bitmask defining TIMER instances reserved to be used outside of nrfx.
 */
#define NRFX_TIMERS_USED        0

/** @} */

#ifdef __cplusplus
}
#endif

#endif // NRFX_GLUE_H__
