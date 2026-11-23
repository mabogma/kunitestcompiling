#pragma once
#include <td/telegram/td_api.h>

namespace telegram_permissions {
inline bool canPublishChannelPost(const td::td_api::ChatMemberStatus* status) {
    using namespace td::td_api;
    if (!status) return false;
    if (status->get_id() == chatMemberStatusCreator::ID) {
        return static_cast<const chatMemberStatusCreator&>(*status).is_member_;
    }
    if (status->get_id() != chatMemberStatusAdministrator::ID) return false;
    const auto& rights = static_cast<const chatMemberStatusAdministrator&>(*status).rights_;
    return rights && rights->can_post_messages_;
}
}
