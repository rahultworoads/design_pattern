
from haversine import distance


class OrderManagement:

    def __init__(self, orders, delivery_executives):
        self.orders = orders
        self.delivery_executives = delivery_executives

    def next_order_to_be_delivered(self):
        pending_orders = list(filter(lambda order: order.status == 'pending', self.orders))
        if len(pending_orders) == 0:
          return None

        max_time_elasped_order = None
        max_time_elapsed = 0
        for pending_order in pending_orders:
            if pending_order.time_elapsed > max_time_elapsed:
                max_time_elasped_order = pending_order
                max_time_elapsed = pending_order.time_elapsed

        return  max_time_elasped_order



    def order_delivery_person_by_waiting_time(self):
        def get_key(person):
            person.waiting_time

        free_delivery_persons = list(filter(lambda delivery_executive: delivery_executive.status == 'free', self.delivery_executives))

        if len(free_delivery_persons) == 0:
            return None

        sorted(free_delivery_persons, key=get_key, reverse=True)
        return  free_delivery_persons

    @staticmethod
    def calculate_haversine_distance(order, delivery_person):
        return distance(order.restaurant_location['lat'], order.restaurant_location['long'] , delivery_person.current_location['lat'], delivery_person.current_location['long'])

    def assign_order_to_delivery_person(self, given_order, free_delivery_persons):
        # just taking random high value
        lowest_first_mile = 100000
        assigned_delivery_person = None

        for free_delivery_person in free_delivery_persons:
            dist = OrderManagement.calculate_haversine_distance(given_order, free_delivery_person)
            if lowest_first_mile > dist:
                lowest_first_mile = dist
                assigned_delivery_person = free_delivery_person


        return assigned_delivery_person




