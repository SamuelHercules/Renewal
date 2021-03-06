-- This file is part of RagEmu.
-- http://ragemu.org - https://github.com/RagEmu/Renewal
--
-- Copyright (C) 2016  RagEmu Dev Team
--
-- RagEmu is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with this program.  If not, see <http://www.gnu.org/licenses/>.

--
-- Upgrade file to be used when going from eAthena to RagEmu
-- Note: If you're not up to date with eAthena, go through their upgrade files first and run them before this file.
-- Note: After runing this file run RagEmu upgrade files.
--

-- Adds 'I' and 'X' to `type` in `picklog` table
ALTER TABLE `picklog` MODIFY `type` ENUM('M','P','L','T','V','S','N','C','A','R','G','E','B','O','I','X') NOT NULL DEFAULT 'P';

-- Adds 'D' and 'U' to `type` in `picklog` table
ALTER TABLE `picklog` MODIFY `type` ENUM('M','P','L','T','V','S','N','C','A','R','G','E','B','O','I','X','D','U') NOT NULL DEFAULT 'P';

-- Adds unique ID to `picklog` table
ALTER TABLE `picklog` ADD `nsiuid` BIGINT NOT NULL DEFAULT '0' AFTER `card3`;

-- Change `nsiuid` to BIGINT(20)
ALTER TABLE `picklog` CHANGE `nsiuid` `unique_id` BIGINT( 20 ) NOT NULL DEFAULT '0';

-- Adds 'I' to `type` in `zenylog`
ALTER TABLE `zenylog` MODIFY `type` ENUM('M','T','V','S','N','A','E','B','I') NOT NULL DEFAULT 'S';

-- Adds 'D' to `type` in `zenylog`
ALTER TABLE `zenylog` MODIFY `type` ENUM('M','T','V','S','N','A','E','B','I','D') NOT NULL DEFAULT 'S';

-- Add 'P' and 'C' types in `zenylog`
ALTER TABLE `zenylog` MODIFY `type` ENUM('T','V','P','M','S','N','D','C','A','E','I','B') NOT NULL DEFAULT 'S';
