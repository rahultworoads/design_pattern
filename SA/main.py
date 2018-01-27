import argparse
import json

from order_management import OrderManagement
from order import Order
from delivery_executive import DeliveryExecutive


def parse_args():
    """
    Returns: List of arguments passed to the Grid client, after parsing
    """
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input', metavar='json',
                        help='Input Json file')
    return parser.parse_args()


def orders(config):
    """
    Returns list of order
    """
    def get_order(ord):
        order = Order(ord['restaurant_location'], ord['order_time'], ord['id'], "pending")
        return order

    return list(map(get_order, config))


def delivery_executives(config):
    """
    Returns the delivery executive's List

    """
    def get_delivery_executive(de):
        de = DeliveryExecutive(de['id'], de['current_location'], de['last_delivered_time'], "free")
        return de

    return list(map(get_delivery_executive, config))


def main():

    args = parse_args()
    config = json.load(open(args.input))

    assignments = []

    order_management = OrderManagement(orders(config["Orders"]), delivery_executives(config["delivery_executives"]))

    next_order = order_management.next_order_to_be_delivered()
    while next_order:
        delivery_persons_ordered = order_management.order_delivery_person_by_waiting_time()
        if delivery_persons_ordered == None:
            print("\n**************Now All delivery guys are busy********\n")
            break
        else:
            assigned_delivery_person = order_management.assign_order_to_delivery_person(next_order, delivery_persons_ordered)
            # update status of order and delivery person
            next_order.status = "enroute"
            assigned_delivery_person.status = "busy"
            assignments.append( {"order_id" : str(next_order.id),
                                  "delivery_executive_id"  : str(assigned_delivery_person.id)})
        next_order = order_management.next_order_to_be_delivered()

    print("\n---------------Assigned order to Executives------------\n")
    print(assignments)


if __name__ == "__main__":
    main()
