The environments folder exists because we cannot guarantee that
we have the same node ids across all the various menu links. We could
use aliases however those too are unstable and subject to change.

The only way I see that may be stable over time is to fix menus to
the environment that is hosting the menu set. This will allow us to
version differences between the linked nodes by environment and still
maintain transaltions and "active" tracking aspects of menu items.