# allow entering bootloader (hold Esc while plugging in keyboard)
BOOTMAGIC_ENABLE = yes
# automatically shifts key when it's hold for threshold
AUTO_SHIFT_ENABLE = yes
# doesn't work, keyboard is unresponsible after it is enabled
DYNAMIC_MACRO_ENABLE = no
# enable locking next key that is pressed
KEY_LOCK_ENABLE = yes
# enable vim-like leader
LEADER_ENABLE = yes
# enable custom key overrides in keymap.c
KEY_OVERRIDE_ENABLE = yes
# enable sending different keycode on fast multiple presses
TAP_DANCE_ENABLE = yes
# enable changing tapping timeout dynamically
DYNAMIC_TAPPING_TERM_ENABLE = yes
# enable unicode input via UC(hex)
UNICODE_ENABLE = yes

# disable unused systems for smaller binary size
# no debug support
CONSOLE_ENABLE = no
# disable some built-in magic commands https://github.com/qmk/qmk_firmware/blob/master/docs/feature_command.md
COMMAND_ENABLE = no
# disable mouse keys
MOUSEKEY_ENABLE = no

# takes longer to compile for smaller binary size
LTO_ENABLE = yes
