/*
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/app_version.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

#define HEARTBEAT_PERIOD_MS 1000

int main(void)
{
	LOG_INF("HAST chamber firmware v%s on %s", APP_VERSION_STRING, CONFIG_BOARD_TARGET);

	while (1) {
		LOG_INF("uptime: %lld ms", k_uptime_get());
		k_msleep(HEARTBEAT_PERIOD_MS);
	}

	return 0;
}
