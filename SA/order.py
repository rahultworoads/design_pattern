from datetime import datetime

class Order:

    def __init__(self, restaurant_location, order_time, id, status):
        self.id = id
        self.restaurant_location = restaurant_location
        self.order_time = order_time
        self.status = status
        self.time_elapsed = ((datetime.now() - datetime.strptime(order_time, "%Y-%m-%d %H:%M:%S")).total_seconds())/60


