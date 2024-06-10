pub mod iris;
pub mod mnist;


// mod => define module(library)
pub mod agent {
    // compile voting.proto, and make rust module named voting
    tonic::include_proto!("agent");
}

