class ElectronicDevice:
    def __init__(self):
        self.runs_on_battery = 0
        self.runs_on_power = 1
        self.is_on = False

    def power_on(self):
        self.is_on = True
        print(f"The electronic device is on : {self.is_on}")


class PocketGadget(ElectronicDevice):
    def __init__(self):
        self.runs_on_battery = 1

    def unlock(self):
        self.is_on = True
        print(f"The Pocket Gadget is unlocked : {self.is_on}")


class Phone(PocketGadget):
    pass


samsung = Phone()
samsung.power_on()
samsung.unlock()
