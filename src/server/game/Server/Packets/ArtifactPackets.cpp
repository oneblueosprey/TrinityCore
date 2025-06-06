/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ArtifactPackets.h"

namespace WorldPackets::Artifact
{
ByteBuffer& operator>>(ByteBuffer& data, ArtifactPowerChoice& artifactPowerChoice)
{
    data >> artifactPowerChoice.ArtifactPowerID;
    data >> artifactPowerChoice.Rank;
    return data;
}

void ArtifactAddPower::Read()
{
    _worldPacket >> ArtifactGUID;
    _worldPacket >> ForgeGUID;
    _worldPacket >> Size<uint32>(PowerChoices);
    for (ArtifactPowerChoice& artifactPowerChoice : PowerChoices)
        _worldPacket >> artifactPowerChoice;
}

void ArtifactSetAppearance::Read()
{
    _worldPacket >> ArtifactGUID;
    _worldPacket >> ForgeGUID;
    _worldPacket >> ArtifactAppearanceID;
}

void ConfirmArtifactRespec::Read()
{
    _worldPacket >> ArtifactGUID;
    _worldPacket >> NpcGUID;
}

WorldPacket const* OpenArtifactForge::Write()
{
    _worldPacket << ArtifactGUID;
    _worldPacket << ForgeGUID;

    return &_worldPacket;
}

WorldPacket const* ArtifactRespecPrompt::Write()
{
    _worldPacket << ArtifactGUID;
    _worldPacket << NpcGUID;

    return &_worldPacket;
}

WorldPacket const* ArtifactXpGain::Write()
{
    _worldPacket << ArtifactGUID;
    _worldPacket << uint64(Amount);

    return &_worldPacket;
}
}
