/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "webrtc/api/audio_codecs/ilbc/audio_decoder_ilbc.h"

#include <memory>
#include <vector>

#include "webrtc/base/ptr_util.h"
#include "webrtc/common_types.h"
#include "webrtc/modules/audio_coding/codecs/ilbc/audio_decoder_ilbc.h"

namespace webrtc {

rtc::Optional<AudioDecoderIlbc::Config> AudioDecoderIlbc::SdpToConfig(
    const SdpAudioFormat& format) {
  return STR_CASE_CMP(format.name.c_str(), "ilbc") == 0 &&
                 format.clockrate_hz == 8000 && format.num_channels == 1
             ? rtc::Optional<Config>(Config())
             : rtc::Optional<Config>();
}

void AudioDecoderIlbc::AppendSupportedDecoders(
    std::vector<AudioCodecSpec>* specs) {
  specs->push_back({{"ILBC", 8000, 1}, {8000, 1, 13300}});
}

std::unique_ptr<AudioDecoder> AudioDecoderIlbc::MakeAudioDecoder(
    Config config) {
  return rtc::MakeUnique<AudioDecoderIlbcImpl>();
}

}  // namespace webrtc
