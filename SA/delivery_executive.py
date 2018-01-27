from datetime import datetime


class DeliveryExecutive:
    """
    Represent the executive
    """
    def __init__(self, id, current_location, last_order_delivered_time, status):
        self.id = id
        self.current_location = current_location
        self.last_order_delivered = last_order_delivered_time
        self.status = status
        self.waiting_time = ((datetime.now() - datetime.strptime(last_order_delivered_time, "%Y-%m-%d %H:%M:%S")).total_seconds())/60

    def __repr__(self):
        return '{}: {} {} {} {} {}'.format(self.__class__.__name__,
                                  self.id,
                                  self.current_location,
                                  self.last_order_delivered,
                                  self.status,
                                  self.waiting_time)

    def __cmp__(self, other):
        if hasattr(other, 'waiting_time'):
            return self.waiting_time.__cmp__(other.waiting_time)

    def status(self, new_status):
        self.status = new_status
