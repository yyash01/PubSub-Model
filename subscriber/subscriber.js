import { publisherFunc } from 'c/publisher';
import { registerListener, unregisterListener, unregisterAllListeners, fireEvent } from 'c/pubSubConnector';

lwc starting point: {
    connectedCallback(){
        /*
        1st param : event-name
        2nd param : method to invoke
        3rd param : this argument of lwc
         */
        registerListener('EventFromPublisher', this.navigateToOrgChart, this);
    }

    disconnectedCallback() {
        unregisterAllListeners(this);
    }
}