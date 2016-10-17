package net.juniper.contrail.sandesh;

import java.net.URI;

public class VCenterPluginReq {
    URI uri;
    // required params parsed from URI

    // optional params

    public VCenterPluginReq(URI uri) {
        this.uri = uri;
    }
}
