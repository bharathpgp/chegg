
#!/bin/sh
if [ "$#" -ne 1 ]; then
    echo "Usage: ./dmesg.sh [argument]"
    echo "Argument any one of: XFS, drm, systemd, ACPI or PM"
    exit 1
fi

if [[ "$1" = "XFS" || "$1" = "drm" || "$1" = "systemd" || "$1" = "ACPI" || "$1" = "PM" ]]; then
    cat /home/fabbasi/TEST2/dmesg | grep -w "$1"
else
    echo "Argument only be: XFS, drm, systemd, ACPI or PM"
fi
